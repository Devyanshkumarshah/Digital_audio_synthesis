#include<stdio.h>
#include<math.h>

int main()
{
    float sample_per_second = 44100;    //no of sample per second, sampling rate which a hardware understand 
    int tone_freq = 440;      //frequency in Hz
    int duration = 4;        //for 2 sec 
    int max_value_encoding = 32767;    //highest 16 bit signed number for amplitude

    int i = 0;
    int total_sample = duration * sample_per_second;   

    float time = 0;
    float angle;

    short int sample;

    FILE *f;       /*this is a coustom datatype, the samples are being saved inthis file */
    
    f = fopen("sine.raw", "wb");   //opens a file in write mode 
    if(f == NULL){
        printf("could not open file.\n");
        return -1; //if it unable to open a file then exit out of the function " -1 "
    }

    while (i < total_sample) {      //created loop 
        time = i +(1/sample_per_second);                        
        angle = 2 * 3.14 * tone_freq * time;
        
        sample = max_value_encoding * sin(angle);

        fwrite(&sample, 2, 1, f);    
        printf("%d ", sample);
        i = i +1;
    }
    fclose(f);    //this function is used to close the file
    return 0;
}