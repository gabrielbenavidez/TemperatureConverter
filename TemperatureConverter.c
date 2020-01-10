/*=============================================================================
 | Source code: TemperatureConverter.c
 | Author: Gabriel Benavidez
 |
 |
 | Language: The C language
 |
 | Compile/Run: To Compile program: gcc TemperatureConverter.c –o TemperatureConverter.out
 |              To Run program: ./TemperatureConverter.out
 | +-----------------------------------------------------------------------------
 |
 | Description: This program takes a users input which represents a "step" increment number.
 |              The program then calculates the conversion from Fahrenheit to Celsius as well as Celsius to Fahrenheit or temperatures ranging from -80.0 until 320.0 degrees.
 |              The formaula's which will be used to convert are the Celsisus to Fahrenheit as well as the Fahrenheit to Celsius formula which are
 |
 |              (Constant°C × 9/5) + 32 = Fahrenheit conversion
 |                                 and
 |              (Constant°F − 32) × 5/9 = Celsius conversion
 |
 |              The program then returns the resulting conversion and  displays the result while incrementing the next number to be converted by the increment number that the user specified.
 |              While printing the results, the program prints an empty line after every 10 temperautre conversions.
 |
 | Input: The input is from the user via keyboard. The input should be an integer number.
 |
 | Output: The program outputs line by line the Farenhiet conversion to Celsius as well as the Celsius conversion to Fahrenheit
 |         while incrementing the number converted by the number the user input.
 |         The program also outputs an empty line after every 10 conversions printed.
 |
 | Process: 1. The program displays it's purpose
 |          2. The user is prompted to input an integer number to be used in the step incrementation.
 |          3. While the current conversion number is less than 320.0 call the conversion methods to convert the current number to Fahrenheit and Celsius and return result.
 |          4. If the current line count is less than 10 print the resulting conversion as well as the number it was converted from, if not print an empty line then reset the line count.
 |          5. Increment the current Fahrenheit and current Celsius value by the number the use specified and repeat steps 3, 4 and 5 again until condition is satisfied.
 |          6. once condition is satisfied the program is terminates without any errors.
 |
 | Required Features Not Included: All required features are included.
 |
 | Known Bugs: None; the program operates correctly
 |
 | *===========================================================================*/

#include <stdio.h>
#define NOERROR 0;
#define RANGEHIGH 9
#define RANGELOW 1
#define LOWTEMP -80.0
#define HIGHTEMP 320.0
#define LINEMAX 10
#define LINECOUNT 0

void printHeading(void);
void printResult(float currentFahrenheit, float currentCelsius, float previousFahrenheit, float previousCelsius);
float convertToFahrenheit(float c);
float convertToCelsius(float f);

int main(void) {
    int input = 0;
    float currentFahrenheit = LOWTEMP;
    float currentCelsius = LOWTEMP;
    float resultFahrenheit = 0.0;
    float resultCelsius = 0.0;
    
    printf("This program converts temperatures in increments from -80.0 to 320.0 degrees based on the range you provide\n");
    do{
        printf("Please enter a number from 1-9: ");
        scanf( "%d", &input);
    }while (input < RANGELOW || input > RANGEHIGH );
    
    printHeading();
    
    while(currentFahrenheit <= HIGHTEMP && currentCelsius <= HIGHTEMP){
        resultFahrenheit = convertToFahrenheit(currentCelsius);
        resultCelsius = convertToCelsius(currentFahrenheit);
        
        if(lineCount < LINEMAX){
            printResult(currentFahrenheit,currentCelsius,resultFahrenheit,resultCelsius);
                LINECOUNT = LINECOUNT + 1;;
        }
        else{
            printf("\n");
            LINECOUNT = 0;
        }
        currentFahrenheit = currentFahrenheit + input;
        currentCelsius = currentCelsius + input;
    }
    return NOERROR;
};


/*---------------------------- convertToCelsuis ----------------------------
 | Function: convertToCelsuis()
 |
 | Purpose: Converts a Fahrenheit float into a Celsius float number
 |
 | @param float named Farenheit
 |
 | @return float of the Fahrenheit parameter after being converted to Celsius
 |
 | *** The Fahrenheit to Celsius formula is: (Constant°F − 32) × 5/9 ***
 *-------------------------------------------------------------------*/
float convertToCelsius(float fahrenheit){
    float celsius = ( ( ( fahrenheit - 32 ) * 5) / 9);
    return celsius;
}


/*---------------------------- convertToFahrenheit ----------------------------
 | Function convertToFahrenheit()
 |
 | Purpose: Converts a Celsius float into Fahrenheit a float number
 |
 | @param float named Celsius
 |
 | @return float of the Celsius parameter after being converted to Fahrenheit
 |
 | *** The Celsius to Fahrenheit formula is: (Constant°C × 9/5) + 32 ***
 *-------------------------------------------------------------------*/

float convertToFahrenheit(float celsius){
    float fahrenheit = ( ( ( celsius * 5 ) / 9 ) + 32);
    return fahrenheit;
}


/*---------------------------- printResult ----------------------------
 | Function printResult()
 |
 | Purpose: This method prints the results of both method converisons
 |
 | @param float currentFahrenheit, float currentCelsius, float resultFahrenheit, float resultCelsius
 |              These parameters are the values of the original temperature as well as its converted equivalent
 |
 | @return none
 *-------------------------------------------------------------------*/
void printResult(float currentFahrenheit, float currentCelsius, float resultFahrenheit, float resultCelsius){
    printf("%20.1f",currentFahrenheit);
    printf("%10.1f ",resultCelsius);
    printf("%11.1f ",currentCelsius);
    printf("%13.1f \n",resultFahrenheit);
}

/*---------------------------- printHeading ----------------------------
 | Function printHeading()
 |
 | Purpose: This method prints the heading of the conversion chart to be displayed before the resulting conversions are shown
 |
 | @param none
 |
 | @return none
 *-------------------------------------------------------------------*/
void printHeading(){
    printf("\n");
    printf("%20s","Fahrenheit");
    printf("%3s\t","->");
    printf("%s\t","Celsius");
    printf("%10s","Celsius");
    printf("%3s","->");
    printf(" %s\t","Fahrenheit\n");
    printf("-----------------------------------------------------------");
    printf("\n");
}



