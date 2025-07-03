func kthCharacter(k int) byte {
    var word []byte
    word = append(word, 'a')
    for len(word)<=k{
        for _, b := range word{
            word = append(word, b+1)
        }
        // fmt.Println(string(word))
    }
    return word[k-1]
}