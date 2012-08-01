//
//  Template.h
//  Fireflys
//
//  Created by JCC-Mini on 12-8-1.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef Fireflys_Template_h
#define Fireflys_Template_h

namespace Fireflys
{

    template <typename T>
    class SharedPtr
    {
    public:
        struct Holder
        {
            T* ptr;
            unsigned int refCount;
        };
        
        SharedPtr()
        {
            mHolder = new Holder;
            mHolder->ptr = NULL;
            mHolder->refCount = 0;
        }
    
        SharedPtr(T* ptr)
        {
            mHolder = new Holder;
            mHolder->ptr = ptr;
            mHolder->refCount = NULL == ptr ? 0 : 1;
        }
    
        SharedPtr(const SharedPtr& rhs)
        : mHolder(rhs.mHolder)
        {
            if (this == &rhs)
                return;
            
            mHolder->refCount++;
        }
    
        ~SharedPtr()
        {
            Release();
        
            assert(mHolder);
        
            if (mHolder->refCount == 0)
            {
                delete mHolder;
                mHolder = NULL;
            }
        }
        
        SharedPtr& operator=(const SharedPtr& rhs)
        {
            if (this == &rhs)
                return *this;
            
            if (NULL == mHolder->ptr || mHolder->ptr == rhs.mHolder->ptr)
            {
                delete mHolder;
            }
            else
            {
                Release();
            }
            
            mHolder = rhs.mHolder;
            mHolder->refCount++;
            
            return *this;
        }
                
        bool operator==(T* p) const
        {
            return mHolder->ptr == p;
        }

        bool operator==(const SharedPtr& rhs) const
        {
            return mHolder->ptr == rhs.mHolder->ptr;
        }
    
        T& operator*()
        {
            assert(mHolder->ptr);
        
            return *mHolder->ptr;
        }
    
        T* operator->()
        {
            assert(mHolder->ptr);
        
            return mHolder->ptr;
        }
    
        operator T*()
        {
            return mHolder->ptr;
        }
        
    protected:
        void Release()
        {
            assert(mHolder->refCount > 0);
        
            mHolder->refCount--;
            if (mHolder->refCount == 0)
            {
                delete mHolder->ptr;
                mHolder->ptr = NULL;
            }
        }

        Holder* mHolder;
    };
    
}

#endif
