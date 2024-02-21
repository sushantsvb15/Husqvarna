# Husqvarna
# COMPILATION STEPS

  1. Run following command on cmd in windows to compile the code "**gcc -o husqvarna husqvarna.c**"
  2. Output file will be generated with the name "**husqvarna**".
  3. Run the program on cmd using follwoing command "**.\husqvarna.exe**".

# EXAMPLE OUTPUT WITH CORRECT INPUT

  *** Input non negative odd integers every 5 seconds till 1 minute,
    provide single number at a time ***

  Provide non negative odd integer below 100: 3
  
  Provide non negative odd integer below 100: 5
  
  Provide non negative odd integer below 100: 7
  
  Provide non negative odd integer below 100: 9
  
  Provide non negative odd integer below 100: 1
  
  Provide non negative odd integer below 100: 19
  
  Provide non negative odd integer below 100: 13
  
  Provide non negative odd integer below 100: 21
  
  Provide non negative odd integer below 100: 11
  
  Provide non negative odd integer below 100: 17
  
  *** End of user input time, 1 minute complete ***
  
  *** Old Array ***
  3 5 7 9 1 19 13 21 11 17
  
  *** New Array ***
  1 0 1 0 1 0 1 0 1 0 1 0 1 0 0 0 1 0 1 0 1

  # EXAMPLE OUTPUT WITH WRONG INPUTS

    *** Input non negative odd integers every 5 seconds till 1 minute,
    provide single number at a time ***

Provide non negative odd integer below 100: 0

!!! Wrong input, Number needs to be odd number !!!

Provide non negative odd integer below 100: -1

!!! Wrong input, number beyond permitted limits !!!

Provide non negative odd integer below 100: a
Invalid input. Please enter a valid number.
Provide non negative odd integer below 100: 20

!!! Wrong input, Number needs to be odd number !!!

Provide non negative odd integer below 100: 3

Provide non negative odd integer below 100: 3

!!! Input is duplicate please provide unique value !!!

Provide non negative odd integer below 100: 5

Provide non negative odd integer below 100: 7

Provide non negative odd integer below 100: 0

!!! Wrong input, Number needs to be odd number !!!

Provide non negative odd integer below 100: 9

Provide non negative odd integer below 100: 11

*** End of user input time, 1 minute complete ***

*** OLD ARRAY ***

3 5 7 9 11

*** NEW ARRAY ***

0 0 1 0 1 0 1 0 1 0 1
  
