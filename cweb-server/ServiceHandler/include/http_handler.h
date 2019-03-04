#ifndef HANDLER_H
#define HANDLER_H


#include <iostream>
#include "cpprestsdk.h"

class handler {
    public:
        handler();
        handler(utility::string_t url);
        virtual ~handler();

        pplx::task<void>open(){return m_listener.open();}
        pplx::task<void>close(){return m_listener.close();}

    private:
        void handle_get(http_request message);
        void handle_put(http_request message);
        void handle_post(http_request message);
        void handle_delete(http_request message);
        void handle_error(pplx::task<void>& t);        
            
        http_listener m_listener;
        
};

#endif 