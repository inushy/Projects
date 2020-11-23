//Anushka Verma
//06/10/2020
//Portfolio 1 - Lab 2

#ifndef Little_Red_Counting_Hood_h
#define Little_Red_Counting_Hood_h

class Count
{
public:

   Count(int n);
   void Inc1(int x);
   void Inc10(int x);
   void Inc100(int x);
   void Inc1000(int x);
   bool overf();
   void reset();
   int  getCount();
   bool above;
   void setLim(int n);
   int  getLim();

private:

   int num;
   int max;

};
//Count::Count(int n): num(),max()
//{
//}

#endif /* Little_Red_Counting_Hood_h */
