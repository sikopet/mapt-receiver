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

#include <string>
#include <thread>
#include <iostream>
#include "UDPListener.h"
#include "S3TPHandler.h"

using namespace std;

void runUDPReceiverThread(DataHandler* dataHandler) {
    try {
        UDPListener udpListener(*dataHandler, 1337);
        udpListener.receiveData();
    } catch (string error) {
        cerr << "ERROR: " << error << endl;
    }
}

int main(int argc, char* argv[]) {
    S3TPHandler s3tpHandler;
    DataHandler dataHandler(s3tpHandler);
    thread udpReceiverThread(runUDPReceiverThread, &dataHandler);
    udpReceiverThread.join();
    return 0;
}