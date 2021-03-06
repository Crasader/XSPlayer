#ifndef PYENVIRONMENT_H
#define PYENVIRONMENT_H

#include <memory>
#include "Core/Constant.h"
#include "Core/Singleton.h"
#include "Core/Task.h"

namespace XSPlayer {

    class PyThreadContext;

    class PyEnvironment : public Singleton<PyEnvironment> {
    public:
        explicit PyEnvironment();
        ~PyEnvironment(void) override;
        bool IsInitSuccessed(void) const { return m_bInitSuccess; }

        static void AddSysPath(const String& path);
        static int RunSampleString(const char* sampleString, int* flag = nullptr);
        static void TracebackError(void);
        static void PySalfRelease(void* pPyObject);

        static PyThreadContext* Create();
        static void ReleaseThreadContext(PyThreadContext* pContext);
        

    private:
        void Init(void);
        void UnInit(void);

    private:
        bool m_bInitSuccess = false;
    };
}

#endif // !PYENVIRONMENT_H
