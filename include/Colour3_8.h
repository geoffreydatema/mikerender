#pragma once

class Colour3_8 {
    private:
        int components[3];

    public:
        Colour3_8();
        Colour3_8(int x, int y, int z);
        void print();
};
