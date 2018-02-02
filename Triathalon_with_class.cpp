#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>//gives me qsort
using namespace std;
class Triathlon
{
    int completion_time;
    int highest_effect_time;
    int swim_total;

public:
    Triathlon();
    struct person
    {
        int order;
        int swim;
        int bike;
        int run;
        int eff_time; 
    };
    void print_sequence(struct person, int);
    void sort_people();
    int get_swim_total(struct person);
    static int compare(void, void);
};

Triathlon::Triathlon()
{
    completion_time = 0;
    highest_effect_time = 0;
    swim_total = 0;
}

static int Triathlon::compare(const void *s1, const void *s2)
{
    const person *p1 = (person*) s1, *p2 = (person*) s2;
    return (p1->eff_time - p2->eff_time) * -1;
}

int get_swim_total(struct person *camper)
{
    for(int i = 0; i < n; i++)
    {
        swim_total += camper[i].swim;
    }
    return swim_total;
}


void Triathlon::print_sequence(struct person *camper, int n)
{
    cout << "Sequence: ";
    for (int i = 0; i < n; i++)
    {
        if(i == n - 1)
        {
            cout << camper[i].order;
        }
        else
        {
            cout << camper[i].order << ",";
        }
        
    }
    cout << endl;
}
int Triathlon::get_highest_effect_time(struct person *camper, int n)
{
    int highest_left_over_time = 0;
    int swim_time_left = 0;
    
    for(int i =1; i < n; i++)
    {
        swim_time_left += camper[i].swim;
    }
    
    for(int i = 0; i < n-1; i++)
    {
        camper[i].eff_time -=swim_time_left;
        swim_time_left -= camper[i + 1].swim;
    }
    
    for(int i = 0; i < n; i++)
    {
        if(camper[i].eff_time > highest_left_over_time)
        {
            highest_left_over_time = camper[i].eff_time;
        }
    }

    return highest_left_over_time;
}

int main()
{
    
	ifstream getAthletes;
	int c, s, r, b; //integer variables for the ones we want in file
	char a; //for finding characters in file when reading
    int n = 3;//size of struct array
    int counter = 0;
    struct person camper[n];//create 3 instances of structure person, basically create 3 people
    int highest_value = 0;
    int completion_time = 0;
    int swim_total = 0;
    Triathlon T;
	getAthletes.open("pa3_test.txt");

    if(!getGraph)
    {
        cout << "file did not open" << endl;
        return 0;
    }
    else
    {
        cout <<"file opened" << endl;
        while(getGraph >>c>>a>>a>>s>>a>>b>>a>>r>>a)
        {
            camper[counter].order = c;
        	camper[counter].swim = s;
            camper[counter].bike = b;
            camper[counter].run = r;
            camper[counter].eff_time = b + r;
            counter++;
        }
        
    }
    
    
    T.print_sequence(camper, n);
    highest_value = T.get_highest_effect_time(camper, n);
    swim_total = T.get_swim_total(camper);
    completion_time = swim_total + highest_value;
    cout << "Completion time: " << completion_time << endl;

    




    
}
