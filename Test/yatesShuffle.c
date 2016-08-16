/**
 * yatesShuffle.c
 *
 * Attempt at creating a Fisher and Yates Shuffle
 * to randomnize a char array
 *
 * Dom Letourneau 16 August 2016
 *
 * Coded using Vim on a RaspPi 3
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #include <time.h>
 #include <sys/time.h>
 
 int main()
 {
    char baseKey[70] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9','0',' ',',','.','?','(',')','[',']'};
    char temp;
    int roll;
    int keyCount=0;
    
    // Seed the random generator, allows for quick calls, but I'll take advice on that.
    struct timeval t1;
    gettimeofday(&t1, NULL);
    srand(t1.tv_usec * ti.tv_sec);
    
    while(keyCount < 4)
    {
      for(int i=70;i>1;i++)
      {
        // Get a random index of the unstriked chars
        roll = rand()%i;
        
        // Swap the striked char with the one at the current index
        temp = baseKey[roll];
        baseKey[roll] = baseKey[i-1];
        baseKey[i-1] = temp;
      }
      
      // Open the output file in append mode
      FILE* keys = fopen("keyTest.txt", "a");
      if (keys == NULL)
      {
        printf("Can't open keyTest.txt");
        return 1;
      }
      
      // Write the key char by char
      for(int i=0;i<70;i++)
        fwrite(&baseKey[i], sizeof(char), 1, keys);
      
      fwrite("\n", sizeof(char), 1, keys);
      
      // TESTING add a line change to see the different key set better during testing
      if (keyCount == 3)
        fwrite("\n", sizeof(char), 1, keys);
      
      fclose(keys);
      keyCount++;
    }
  }
