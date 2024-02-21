#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdbool.h>

#define MAX_ARR_SIZE    12
#define SLEEP_TIME      5000 // In millis
#define USR_INP_MAX_VAL 100
#define TIMEOUT         60

/*!
    \brief  Function will create a character array from the max value of the input array.
            It will then write character '1' to the array index correspoding to the numbers 
            provided by user.
            It will write character '0' to the remaining indexes.

    \param  input_arr   Array of the user input.
    \param  inp_count   Count of the numbers provided by the user.
*/
void create_arr_from_inp(   const unsigned int *input_arr, 
                            const unsigned int inp_count)
{
    unsigned int max_val = 0;

    if(inp_count == 0)
    {
        printf("\n!!! No input provided !!!\n\n");
        return;
    }

    // Find the max value from input
    for(int i = 0; i < inp_count; ++i)
    {
        if(input_arr[i] > max_val)
        {
            max_val = input_arr[i];
        }
    }

    // Create the character array of size max input value.
    char arr[max_val + 1];
    memset( arr, 
            0, 
            max_val + 1);

    // Write character '0' to all the array elements.
    memset( arr, 
            '0', 
            max_val);

    // Write character '1' to all the indexes corresponding to the user inputs.
    for(int i = 0; i <= inp_count; ++i)
    {
        arr[input_arr[i] - 1] = '1';
    }

    // Print the New array
    printf("\n\n*** New Array ***\n");
    for(int i = 0; i < max_val + 1; ++i)
    {
        printf("%c ", arr[i]);
    }

    printf("\n\n");
}

/*!
    \brief  Function checks if the input value is already present in the array or not.

    \param  input_arr   Array in which the duplicate value has be searched.
    \param  inp         Value to be searched for in the input array.

    \return True: If the Value is present in the array
            False: If the value is not present in the array.
*/
bool inp_is_duplicate(  const unsigned int *input_arr, 
                        const unsigned int inp)
{
    for(int i = 0; i < MAX_ARR_SIZE; ++i)
    {
        if(inp == input_arr[i])
        {
            return true;
        }
    }
    return false;
}

/*!
    \brief  Function Asks for input from the user.
            If the input is invalid it will promt the user to provide valid input.
            It will run for predefined amount of time with a certain time period between each 
            user input.

    \param  input_arr   This is the input array into which the user input values will be copied into.

    \return Returns the count of the input numbers given by the user.
*/
unsigned int get_user_input(unsigned int *input_arr)
{
    time_t strt_time = time(NULL);
    int inp = 0;
    int arr_idx = 0;

    printf("\n*** Input non negative odd integers every 5 seconds till 1 minute, \
            \n    provide single number at a time ***\n\n");

    while (1)
    {
        // Check timeout condition
        time_t curr_time = time(NULL);
        if((curr_time - strt_time) > TIMEOUT)
        {
            printf("\n*** End of user input time, 1 minute complete ***\n");
            break;
        }
        
        printf("Provide non negative odd integer below %i: ", USR_INP_MAX_VAL);
        
        // Get User Input.
        #if 0
        if(scanf("%u", &inp) != 1)
        {
            printf("\n!!! Unsupported user input !!!\n");
            while (getchar() != '\n');
            
            continue;
        }
        while (getchar() != '\n'); // Flush out anything remaining in the input buffer
        #endif

        #if 1
            char input[100];
            if (fgets(input, sizeof(input), stdin) == NULL) {
                printf("Error reading input.\n");
            }

            // Use sscanf to parse the integer from the input
            if (sscanf(input, "%d", &inp) != 1) {
                printf("Invalid input. Please enter a valid number.\n");
                continue;
            }

        #endif

        // Check validity of the input.
        if((inp < 0) || (inp > USR_INP_MAX_VAL))
        {
            printf("\n!!! Wrong input, number beyond permitted limits !!!\n\n");
            continue;
        }
        else if ((inp % 2) == 0)
        {
            printf("\n!!! Wrong input, Number needs to be odd number !!!\n\n");
            continue;
        }

        if(inp_is_duplicate(input_arr, inp))
        {
            printf("\n!!! Input is duplicate please provide unique value !!!\n\n");
            continue;
        }

        // Copy valid input into the array.
        input_arr[arr_idx] = inp;
        ++arr_idx;

        Sleep(SLEEP_TIME);
    }

    return arr_idx;
}   

/*!
    \brief  Start of the application.
            Calls the function to get inputs from user.
            Then creates a new array from the user inputs.
*/
int main(void)
{
    unsigned int usr_input_arr[MAX_ARR_SIZE] = {0};
    unsigned int input_count;

    input_count = get_user_input(usr_input_arr);

    printf("\n*** Old Array ***\n");
    int i = 0;
    while (i < input_count)
    {
        printf("%u ", usr_input_arr[i]);
        ++i;
    }

    create_arr_from_inp(usr_input_arr, 
                        input_count);
    
    return 0;
}