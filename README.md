# DNA-Statistics
A simple analysis program to computer basic statistics for a list of DNA strings.

@author Adrienne Bergh

# Program components
- Accepts as a command line argument the name of a text file that contains an arbitrary list of DNA strings.
- Computes the sum, mean, variance, and standard deviation of the length of the DNA strings in the list. 
- Computes the relative probability of each nucleotide (A,C,T, or G), as well as the probability of each nucleotide bigram (AA, AC, AT, AG, CA, CC, CT, CG, etc) across the entire collection.
- Output the labeled results to a file called Results.out.
- Generate 1000 DNA strings whose lengths follow a Gaussian distribution with the same mean and variance as calculated above. The relative frequency of nucleotides will also follow the statistics calculated above. Append the 1000 strings to the end of Results.out.
- Ask the user if they want to process another list.

# To Run (from Mac command line):
- g++ *.cpp
- ./a.out
