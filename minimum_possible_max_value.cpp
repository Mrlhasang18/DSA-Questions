//Minimize the maximum of 2 arrays
class Solution {
public:
    long gcd(long a, long b)
    {
        if((a%b)==0){
            return b;             //gcd using recursive function is created so as to calculate the lcm integer that are present in both the arrays
        }else{
            return gcd(b, a%b);
        }
    }
    
    void bs(long l, long h, int divisor1, int divisor2, long lcm, long * ans, int c1, int c2){
        if(l<=h){
            long m=(l+h)/2;  //total elements from left(1) to right(h) = m
            
            long a, b, c;
            
            a=m-(m/divisor1);   //a are number of elements that are not divisible by divisor1   m/divisor1 are those numbers that are divisible by divisor 1
            b=m-(m/divisor2);
            c=m-(m/divisor1)-(m/divisor2)+(m/lcm);  //(m/lcm) is added so as to add the common element that is deleted from both of the arrays
            
            //cout<<m<<" "<<a<<" "<<b<<" "<<c<<"\n";
            
            if(a>=c1 && b>=c2 && a+b-c>=c1+c2){
                (*ans)=m;
                bs(l, m-1, divisor1, divisor2, lcm, ans, c1, c2); //recursive left binary search
            }else{
                bs(m+1, h, divisor1, divisor2, lcm, ans, c1, c2); //right binary search
            }
        }
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long g=gcd(max(divisor1, divisor2), min(divisor1, divisor2));
        long l=(long(divisor1)*long(divisor2))/g;
        
        long ans=1000000000;
        
        bs(2, 10000000000, divisor1, divisor2, l, (&ans), uniqueCnt1, uniqueCnt2);
        
        return int(ans);
        
    }
};
