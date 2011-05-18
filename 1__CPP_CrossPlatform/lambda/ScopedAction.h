#ifndef __SCOPED_ACTION_HPP__
#define __SCOPED_ACTION_HPP__

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>
#include <assert.h>


class ScopedAction : private boost::noncopyable
{
public:
    typedef boost::function<void()> Callback;

public:
    explicit ScopedAction(const Callback& func) : 
      needAction_(true), 
          function_(func)
    {
    }

    virtual ~ScopedAction()
    {
        Action();
    }

    inline void Release()
    {
        needAction_ = false;
    }

    inline void Reset(const Callback& func)
    {
        Action();
        function_ = func;
        needAction_ = true;
    }

    inline void Reset()
    {
        Action();
    }

private:
    inline void Action()
    {
        if (needAction_)
        {
            try
            {
                function_();
                needAction_ = false;
            }
            catch (...) 
            {
                assert(false);
            }
        }
    }

private:
    Callback function_;
    bool needAction_;
};


#endif