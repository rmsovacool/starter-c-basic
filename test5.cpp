// find approx area under one alternation of sine wave
// Divide by pi to get average since avg=area/interval
//Also find approx area of unit circle

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
	using namespace std;

int main()
{
		cout<<"Hello world"<< endl;
		cout<<"Hello world"<< "\n";
		cout<<"find approx area under one alternation of sine wave" <<endl;
		cout<<"also find approx effective (rms) value" <<endl;


	int npts = 1000;
	double arg;
	double yval = 0.;
	double yval_squared = 0.;
	double sum = 0.;			// sum of y values
	double sum2 = 0.;			// sum of y_squared values

	double interval;
	double average;				// average value of waveform
	double effective;			// effective value of waveform

	double delta_x = M_PI/npts;
	double area;
	double area2;

// area= sum(sin(x)*delta_x / ( npts*delta_x ))
// note redundant mult then divide by delta_x
// next we will eliminate delta_x after computing avg, effective values

	for (int i=0; i<npts; i++)
	{		
		arg = M_PI * i / npts;
		yval = sin(arg);
		yval_squared= pow(yval,2);					// square for effective value (rms) of waveform
		area = yval*delta_x;						// y*dx
		area2 = yval_squared*delta_x;						// ysquared*dx
		sum = sum + area;			
		sum2 = sum2 + area2;

	}
		interval=npts*delta_x;				//total 'width' on x axis				
		average = sum/interval;				// the meat
		effective = sqrt(sum2/interval);	// potatoes

//		debug
//		cout << "interval= ";
//		cout << interval <<endl;
//		cout << "sum= " << " ";
//		cout << sum <<endl;
//		cout << "sum2= " << " ";
//		cout << sum2 <<endl;
		
		cout << "average= " << " ";
		cout << average <<endl;
		cout << "effective= " << " ";
		cout << effective <<endl;

	cin.get();
	
// now eliminate delta_x and recompute, since delta_x is in numerator and denominator (efffectively cancellling each other
// compute avg, effective values again; less computationally intensive
	sum=0.;
	sum2=0.;											//initialize sum, sum2	cin.get();

	for (int i=0; i<npts; i++)
	{		
		arg = M_PI * i / npts;
		yval = sin(arg);
		yval_squared= pow(yval,2);					// square for effective value (rms) of waveform
		area = yval;								// y without *dx
		area2 = yval_squared;						// ysquared without *dx
		sum = sum + area;			
		sum2 = sum2 + area2;

	}
		interval=npts;							//total 'width' on x axis				
		average = sum/interval;					// the meat
		effective = sqrt(sum2/interval);		// potatoes

		cout << "interval= ";
		cout << interval <<endl;
		cout << "sum= " << " ";
		cout << sum <<endl;
		cout << "sum2= " << " ";
		cout << sum2 <<endl;
		
		cout << "average= " << " ";
		cout << average <<endl;
		cout << "effective= " << " ";
		cout << effective <<endl;
		cout << " " <<endl;

// now find area of a unit circle using rectangles (radius=1)
// x*x + y*y = r*r  equation of a circle
//  then y= sqrt(r*r - x*x)
// compute quarter circle area in quadrant one, then mult by 4 to get total area
		
		double radius = 1.0;						// radius
		double x, y;								// x y values
		delta_x = radius / npts;					// width of rectangle base, small change in x
		area2= 0. ;
		sum= 0. ;
		for (int i=0; i<npts; i++)
	{		
		x = 1. * i / npts;

		y = sqrt(radius*radius - x*x);
		area2= y*delta_x;
		sum = sum + area2;			

//		cout << "x, y= ";
//		cout << x <<endl;
//		cout << y <<endl;
	}
		area = sum;
		cout << "unit circle area= ";
		cout << 4*area <<endl;

		cin.get();
		return 0;

}