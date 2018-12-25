//: ----------------------------------------------------------------------------
//: Copyright (C) 2018 Verizon.  All Rights Reserved.
//: All Rights Reserved
//:
//: \file:    rqst.h
//: \details: TODO
//: \author:  Reed P. Morrison
//: \date:    03/11/2015
//:
//:   Licensed under the Apache License, Version 2.0 (the "License");
//:   you may not use this file except in compliance with the License.
//:   You may obtain a copy of the License at
//:
//:       http://www.apache.org/licenses/LICENSE-2.0
//:
//:   Unless required by applicable law or agreed to in writing, software
//:   distributed under the License is distributed on an "AS IS" BASIS,
//:   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//:   See the License for the specific language governing permissions and
//:   limitations under the License.
//:
//: ----------------------------------------------------------------------------
#ifndef _RQST_H
#define _RQST_H
//: ----------------------------------------------------------------------------
//: Includes
//: ----------------------------------------------------------------------------
#include "is2/srvr/hmsg.h"
#include "is2/support/data.h"
#include <string>
#include <list>
namespace ns_is2 {
//: ----------------------------------------------------------------------------
//: \details: TODO
//: ----------------------------------------------------------------------------
class rqst: public hmsg
{
public:
        // -------------------------------------------------
        // public methods
        // -------------------------------------------------
        rqst();
        ~rqst();
        void clear(void);
        void init(bool a_save);
        const data_t &get_url();
        const data_t &get_url_uri();
        const data_t &get_url_path();
        const data_t &get_url_query();
        const data_t &get_url_fragment();
        const data_t &get_url_host();
        const char *get_method_str();
        const mutable_arg_list_t& get_query_list();
        const mutable_data_map_list_t& get_query_map();
        // Debug
        void show();
        // -------------------------------------------------
        // public members
        // -------------------------------------------------
        // -------------------------------------------------
        // raw http request offsets
        // -------------------------------------------------
        cr_t m_p_url;
        int m_method;
        bool m_expect;
private:
        // -------------------------------------------------
        // private methods
        // -------------------------------------------------
        int32_t parse_uri(void);
        // -------------------------------------------------
        // private members
        // -------------------------------------------------
        bool m_url_parsed;
        char *m_url_buf;
        uint32_t m_url_buf_len;
        data_t m_url;
        data_t m_url_uri;
        data_t m_url_host;
        data_t m_url_path;
        data_t m_url_query;
        data_t m_url_fragment;
        mutable_arg_list_t *m_query_list;
        mutable_data_map_list_t *m_query_map;
};
}
#endif