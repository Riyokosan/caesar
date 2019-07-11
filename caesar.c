#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //int in which the key will be stored if valid
    int key = 0;  
        
    if (argc == 2)
    {
        string s = argv[1];
        
        //initialaziong the int detecting an error in the key
        int e = 0;
        
        //check the content of the key entered
        for (int i = 0; i < strlen(s); i++)
        {
            //if number increment a variable x
            if (s[i] >= '0' && s[i] <= '9')
            {
                key++;  
            }
            //if something else than a number increment e
            else
            {
                e++;
            }
        }
        //error printed if the code contains something else than a number
        if (e != 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        //convert the string into an integer
        else 
        {
            key = atoi(argv[1]);
        }
        printf("Current key: %i\n", key);
    }
    else 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    //request the text to cipher
    string plain = get_string("plaintext: ");
    
    //start printing the ciphered text
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plain); i++)
    {
        //convert each lower case character
        if islower(plain[i])
        {
            printf("%c", (((plain[i] + key) - 'a') % 26) + 'a');
        }
        //convert each upper case character
        else if isupper(plain[i])
        {
            printf("%c", (((plain[i] + key) - 'A') % 26) + 'A');
        }
        //if neither then just print whatever it is
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
    //exit without error
    return 0;
    
}