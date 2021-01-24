class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent == 0)
            return 1.0;
        if(exponent == 1)
            return base;
        if(exponent == -1 && base != 0.0)
            return 1.0 / base;
        if(exponent == -1 && base == 0.0)
            return std::numeric_limits<double>::max();
        bool neg = exponent > 0 ? false : true;
        exponent = abs(exponent);
        return !neg?PowerOfPositive(base,exponent):(1.0/PowerOfPositive(base,exponent));
    }
    
    
    double PowerOfPositive(double base,int exp)
    {
        if(exp == 1)
            return base;
        double tmp = PowerOfPositive(base,exp/2);
        if(exp & 1)
            return tmp * tmp * base;
        else
            return tmp * tmp;
    }
    
};