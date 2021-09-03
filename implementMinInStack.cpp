
/*returns min element from stack*/
int _stack :: getMin()
{
   int val = s.top();
   s.pop();
   int min_ = s.top();
   s.pop();

   s.push(min_);
   s.push(val);
   return min_;
}

/*returns poped element from stack*/
int _stack ::pop()
{
   if(s.empty())
   return -1;
   int val = s.top();
   s.pop();
   int min_ = s.top();
   s.pop();

   int nextEle = s.top();
   s.pop();
   int nextMin_ = s.top();
   s.push(nextEle);

   minEle = nextMin_;
   return val;
}

/*push element x into the stack*/
void _stack::push(int x)
{
    if(s.empty())
    {
        minEle = x;
    }
    
    else if(minEle>x)
    minEle = x;

    s.push(minEle);
    s.push(x);

    
   //Your code here
}
