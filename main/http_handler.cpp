/**
 * Copyright 2014 Lucas Nunes de Lima
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **/

#include "http_handler.hpp"

#include <iostream>
#include <fstream>

#include "http/server.hpp"
#include "logger.hpp"
#include "settings.hpp"

namespace controller
{
    namespace http
    {
        void run()
        {
            using namespace http;

            try
            {
                logger.write("Iniciando servidor HTTP.");
                Server("0.0.0.0", "80", ".").run();
            }
            catch(...)
            {
                logger.write("Erro ao estabelecer servidor HTTP na porta %d.", getSettings().getHttpPort());
            }
        }
    }
}
