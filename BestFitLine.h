#ifndef BESTFITLINE_H
#define BESTFITLINE_H
#include <QLine>
class BESTFITLINE{
    public:
        double xsum;
        double ysum;
        double product;
        double xsquared;
        int size;
        QLineSeries
        void addPoint(double x,double y){
            size++;
            xsum+=x;
            ysum+=y;
            product+=x*y;
            xsquared+=x*x;
        }
        void removePoint(double x,double y){
            size--;
            xsum-=x;
            ysum-=y;
            product-=x*y;
            xsquared-=x*x;
        }
        double intercept(){
            return ((ysum*xsquared)-(xsum*product))/((size*xsquared)-(xsum*xsum));
        }
        double slope(){
            return ((size*product)-(xsum*ysum))/((size*xsquared)-(xsum*xsum*xsum));
        }

};



#endif // BESTFITLINE_H
