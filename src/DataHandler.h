/**
 * Copyright (C) 2016  Jonas Sticha (jonas.sticha@tum.de)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#ifndef MAPT_RECEIVER_DATAHANDLER_H
#define MAPT_RECEIVER_DATAHANDLER_H

#include <list>
#include <tuple>
#include <mutex>
#include "S3TPHandler.h"

using namespace std;

class DataHandler {
private:
    mutex listMutex;
    bool passthroughMode;
    S3TPHandler& s3tpHandler;
    list<tuple<char*, int>> dataList;
public:
    DataHandler(S3TPHandler& s3tpHandler);
    void sendAllStoredData();
    void setPassthroughMode(bool mode);
    void addData(tuple<char*, int> data);
    tuple<char*, int> popData();
    int getNumStoredData();
};


#endif //MAPT_RECEIVER_DATAHANDLER_H
