func ladderLength(beginWord string, endWord string, wordList []string) int {
    wordList = append(wordList, beginWord)
    n := len(wordList)
    eg := make(map[string][]string)

    for i := 0 ; i < n ; i++ {
        for j := 0 ; j < n ; j++ {
            if i != j && diff(wordList[i] , wordList[j]) == true {
                eg[wordList[i]] = append( eg[wordList[i]], wordList[j])
                // eg[wordList[j]] = append( eg[wordList[j]], wordList[i])
            }
        }
    }

    // fmt.Println(eg)

    visited := map[string]bool{}
    for key := range eg {
        visited[key] = false
    }
    queue := []string{beginWord}
    distance := 1
    for len(queue) > 0 {
        // fmt.Println(queue)
        levelSize := len(queue)
        for i := 0 ; i < levelSize ; i++ {
            curr := queue[0]
            queue = queue[1:]
            if curr == endWord {
                return distance
            }
            visited[curr] = true

            for i := range eg[curr] {
                if visited[eg[curr][i]] == false {
                    // fmt.Println(eg[curr][i])
                    queue = append( queue , eg[curr][i])
                }
            }
        }
        distance++
    }
    return 0
}


func diff(a , b string) bool {
    n := len(a)
    d := 0
    for i := 0 ; i < n ; i++ {
        if a[i] != b[i] {
            d++
        }
    }
    if d == 1 {
        return true
    } else {
        return false
    }
}