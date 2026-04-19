//
// Created by kikok on 15/03/2026.
//

#ifndef SEAT_H
#define SEAT_H

#include "iostream"


using namespace std;

class seat {
    private:
      int rowNum;
      int colNum;
      bool isFree;

    public:
      seat();
      seat(int rowNum, int colNum);
      void setasTaken(int taken);
      bool getisTaken() const;
      void setRowNumber(const int row);
      int getRowNumber() const;
      void setColumnNumber(const int column);
      int getColumnNumber() const;    
};

#endif //SEAT_H
