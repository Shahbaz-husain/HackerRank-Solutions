#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int steadyGene(string gene)
{
    // unordered map to count the frequency of each char
    unordered_map<char, int> freq;
    for(int i = 0; i < gene.length(); i++)
        freq[gene[i]]++;

    // stable gene required reason : if all the chars frequency is divisible by 4 that means string length is also divisible by 4
    int stable_gene = gene.length()/4;
    
    // if already all the chars frequencies are stable no need to change anything
    if(freq['A'] == stable_gene and  freq['C'] == stable_gene and freq['G'] == stable_gene and freq['T'] == stable_gene)
        return 0;
        
    // using two pointers algorithm
    int left=0 , right = 0, minL =  gene.length();
    while(true)
    {
        // while any char's frequency is greater than what's required , will those many chars can be replaced
        while(freq['A'] > stable_gene or freq['C'] > stable_gene or freq['G'] > stable_gene or freq['T'] > stable_gene){
            freq[gene[right]]--;
            right++;
            
            if(right == gene.size())
                break;
            
        }
        
        // if all elements needs to be replaced
        if(right == gene.size())
            break;
           
        //  which chars needs to be replaced with 
        while(freq['A'] <= stable_gene and freq['C'] <= stable_gene and freq['G'] <= stable_gene and freq['T'] <= stable_gene){
            freq[gene[left]]++;
            left++;
        }
        
        // if replacements count becomes greater than length of gene , then will take minL as gene length only
        minL = min(right - left + 1, minL);
    }
    
    return minL;
}

int main()
{
    int n ;
    cin >> n;
    
    string gene;
    cin >> gene;
    
    cout << steadyGene(gene);
}