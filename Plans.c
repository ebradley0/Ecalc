/*** 3 main arguments 
        1 Command, ignore this
        2 Type of function be conducted, pass this arg through if statements until they match with a function
            The matched function will connect to a different int main() relating to that function, bringing the rest of the arguments with it
        3 These are the numbers included in the equation

    The function that is chosen will perform the calculation, and return a result, this result will be passed to the concluding function which will print the answer

    FAILSAFES
        - If arguments < 3 state "Not enough information provided"
        - For selecting the type of function, have a final if statement returning an error if none of the function types matched
        

    EXAMPLE : ./ECalc -F = Multiply -A=3 -B=25 .... -N= 23

    int main(stuff?){ -------------------> Choosing function type
        if argument = Add then
            pass add function
            return 0;
        else if argument = Multiply then
            pass multiply function
            return 0;

            ...etc
            
        else 
            Printf("Double check! You did not enter a valid function\n")
            }

        int main (passed arguments?){
for i=1, i=n do {

    multiply stuff idk

    return result;

    send result function?
}
        } ---------> Multiply function



        Result function ----------

        int main(result){
            printf("The answer is %d!", result)
        }
        /**