int divide(double dividend, double divisor) { 

        int negFlag = (dividend < 0 ^ divisor < 0) ? 1 : 0;
        double logDiv = log(abs(dividend)) - log(abs(divisor));
		
		// take antilog to calculate the value 
        double val = exp(logDiv);
        
        if(val >= INT_MAX)
            return negFlag ? INT_MIN : INT_MAX;
    
        return negFlag ? -val : val;    
    }