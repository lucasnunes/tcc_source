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

#include "read_discrete_inputs.hpp"
#include <cstddef>

namespace controller
{
    namespace modbus
    {
        ReadDiscreteInputsResponse::ReadDiscreteInputsResponse(Header& header)
        {
            transaction_id.word = header.getTransition();
            protocol.word = 0u;
            length.word = 0u;
        }

        void ReadDiscreteInputsResponse::appendByte(uint8_t word)
        {
            data.emplace_back(word);
            length.word++;
        }

        std::vector<uint8_t> ReadDiscreteInputsResponse::getData() const
        {
            std::vector<uint8_t> total;
            total.reserve(7 + data.size());

            total.push_back(transaction_id.low);
            total.push_back(transaction_id.high);
            total.push_back(protocol.low);
            total.push_back(protocol.high);
            total.push_back(length.low);
            total.push_back(length.high);
            total.push_back(unit);

            for(size_t i = 0u; i < data.size(); i++)
            {
                total.push_back(data[i]);
            }

            return total;
        }
    }
}
