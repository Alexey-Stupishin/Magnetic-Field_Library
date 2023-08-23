#include "stdDefinitions.h"
#include "mfoGlobals.h"

#include "MagFieldOps.h"
#include "NLFFFLinesTaskQueue.h"
#include "LinesTaskProcessor11.h"
#include "LinesProcessor.h"
#include "agmRKF45.h"

#include "console_debug.h"

__declspec(dllexport) uint32_t mfoGetLinesV(int *N,
    CagmVectorField *v,
    uint32_t _cond, REALTYPE_A chromoLevel,
    REALTYPE_A *_seeds, int _Nseeds,
    int nProc,
    REALTYPE_A step, REALTYPE_A tolerance, REALTYPE_A boundAchieve,
    int *_nLines, int *_nPassed,
    int *_voxelStatus, REALTYPE_A *_physLength, REALTYPE_A *_avField, 
    int *_linesLength, int *_codes,
    int *_startIdx, int *_endIdx, int *_apexIdx,
    uint64_t _maxCoordLength, uint64_t *_totalLength, REALTYPE_A *_coords, uint64_t *_linesStart, int *_linesIndex, int *seedIdx)
{
    nProc = TaskQueueProcessor::getProcInfo(nProc);

    uint32_t rc = 0;

    int maxResult = 50000;

    LQPTaskFactory factory;
    LQPSupervisor *supervisor = new LQPSupervisor(N, v, _cond, chromoLevel,
        _seeds, _Nseeds,
        nProc,
        step, tolerance, boundAchieve,
        _nLines, _nPassed,
        _voxelStatus, _physLength, _avField,
        _linesLength, _codes,
        _startIdx, _endIdx, _apexIdx,
        _maxCoordLength, _totalLength, _coords, _linesStart, _linesIndex, seedIdx, &factory);

    TaskQueueProcessor proc;

    std::vector<ATQPProcessor *> processors;
    for (int i = 0; i < nProc; i++)
        processors.push_back(new LQPProcessor(supervisor, i, v, 0, step, tolerance, 0
            , boundAchieve, chromoLevel, maxResult, _voxelStatus));

    proc.proceed(processors, supervisor);

    console_debug("end of proceed")

    if (_totalLength)
        *_totalLength = supervisor->queue->cumLength;
    if (_nLines)
        *_nLines = supervisor->queue->nLines;
    if (_nPassed)
        *_nPassed = supervisor->queue->nPassed;

    int ns = supervisor->queue->nNonStored;

    console_debug("end of assign")

        for (int i = 0; i < nProc; i++)
        delete processors[i];

    console_debug("processors deleted")

    delete supervisor;

    console_debug("supervisor deleted")

    return ns;
}

__declspec(dllexport) uint32_t mfoGetLines(int *N,
    REALTYPE_A *Bx, REALTYPE_A *By, REALTYPE_A *Bz,
    uint32_t conditions, REALTYPE_A chromo_level,
    REALTYPE_A *seeds, int Nseeds,
    int nProc,
    REALTYPE_A step, REALTYPE_A tolerance, REALTYPE_A toleranceBound,
    int *nLines, int *nPassed,
    int *status, REALTYPE_A *physLength, REALTYPE_A *avField, 
    int *linesLength, int *codes,
    int *startIdx, int *endIdx, int *apexIdx,
    uint64_t maxCoordLength, uint64_t *totalLength, REALTYPE_A *coord, uint64_t *linesStart, int *linesIndex, int *seedIdx)
{
    console_start();

    CagmVectorField *v = new CagmVectorField(Bx, By, Bz, N);

    uint32_t rc = mfoGetLinesV(N,
        v,
        conditions, chromo_level,
        seeds, Nseeds,
        nProc,
        step, tolerance, toleranceBound,
        nLines, nPassed,
        status, physLength, avField,
        linesLength, codes,
        startIdx, endIdx, apexIdx,
        maxCoordLength, totalLength, coord, linesStart, linesIndex, seedIdx);

    delete v;

    console_debug("vector box deleted")

    return rc;
}
