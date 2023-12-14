#include <iostream>
#include <random>
#include <string.h> 


//declare function
bool spin_wheel(int N, double cut_off);


//def main function that will represent the game
// you get to spin wheel N times
// if in any of the N trials, your wheel lands on a number greater than the cut off you win
// if you never land on a number greater than the cut off, you loose
// probability of your wheel landing on a number geater than the cut off is based on a gaussian distribution

int main() {

    int N = 10;
    double cut_off = 1.5;

    bool result = spin_wheel(N, cut_off);

}


// define function
bool spin_wheel(int N, double cut_off) {

    // random device class instance, generates random seed number
    std::random_device rd; 

    // pass utilize random seed into Merseene twister PRNG object (this is your random seed)
    std::mt19937 gen(rd()); 

    bool found_num = false;

    //generate a distribution with std library
    double mean=0;
    double stddev = 1;
    std::normal_distribution<float>  dist(mean, stddev); 

    //iterate N times
    for (int i=0; i < N; i++) {

        //generate a random number from the distribution
        double gen_num = dist(gen);

        
        std::string message = "trial " + std::to_string(i)+ ": " + "you got number " + std::to_string(gen_num);
        std::cout << message << std::endl;
        

        // if number is greater than cut_off, then update flag and cout number
        if (gen_num > cut_off) {

            found_num = true; 
            std::string message1 = "you win! found number higher than cut_off " + std::to_string(cut_off) ; 
            std::string message2 = "your number is " + std::to_string(gen_num);
            std::cout << message1 << std::endl;
            std::cout << message2 << std::endl;
            break;

        }
    }
    if (found_num == false) {

        std::cout << "you lose!" << std::endl;

    }


    //return flag
    return found_num;
}   



