#pragma once

#include "TaskQueueProcessor.h"
#include "WiegelmannTaskQueue11_direct.h"
#include "agmScalarField.h"
#include "agmVectorField.h"

class WQPProcessorD : public ATQPProcessor
{
protected:
    WQPTaskD *this_task;

    int N[3];
    int id;
    double *steps;

public:
    WQPProcessorD(int *_N, int _id, double *_steps) 
        : ATQPProcessor(_id)
        , id(_id)
    {
        memcpy(N, _N, 3 * sizeof(int);
        memcpy(steps, _steps, 3 * sizeof(double);
    }
    virtual ~WQPProcessor() 
    {
    }

    unsigned long Bind(CagmVectorField *_sourceB, CagmScalarField *_sourceW, CagmVectorField *_sourceGradW,
        CagmVectorField *_baseField, CagmVectorField *_baseWeight,
        CagmScalarField *_absField, CagmScalarField *_absWeight,
        CagmScalarField *_losField, CagmScalarField *_losWeight,
        double *_vcos,
        CagmVectorFieldOps *_outF, double *Lt)
    {
        w->Bind(_sourceB, _sourceW, _sourceGradW, _baseField, _baseWeight, _absField, _absWeight, _losField, _losWeight, _vcos, _outF, Lt);
        return 0;
    }

    virtual bool setTask(ATQPTask * _task)
    {
        bool finish = ATQPProcessor::setTask(_task);
        if (!finish)
        {   // cast *_task to the real object:
            this_task = (WQPTaskD *)_task;
        }
        return finish;
    }

    virtual bool proceed()
    {
        w->setTaskParams(this_task->getData(), this_task->getQueueID());
        w->ActionCore();

        return true;
    }
};

