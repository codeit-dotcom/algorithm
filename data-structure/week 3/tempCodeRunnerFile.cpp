
        if (pHAsh == H[i])
         {  
        if   (areEqual(t.substr(i, s.size()), s))
          ans.push_back(i);  
         }  
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrencesfast(read_input()));
    return 0;
}
