int isValid(string str) {

    int dot = 0;
    string temp = "";

    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] == '.'){
            dot++;
            if(temp.empty()) 
                return false;
                
            else if(temp.size() > 1 && temp[0] == '0') 
                return false;
            
            int num = stoi(temp);
                
            if(num < 0 || num > 256) 
                return false;
            temp = "";
        }
        else 
            temp += str[i];
    }
        
    if(temp.empty()) 
        return false;
    else if(temp.size() > 1 && temp[0] == '0') 
        return false;
        
    int num = stoi(temp);
        
    if(num < 0 || num > 256) 
        return false;
        
    return dot == 3 ? true : false;
}

// Input: str = 222.111.111.111
// Output: true
