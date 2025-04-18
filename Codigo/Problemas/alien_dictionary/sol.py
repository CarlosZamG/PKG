def compare_words(word_1: str, word_2: str, order_map: dict):
    for j, c in enumerate(word_1):
        if j >= len(word_2):
            return False

        if c != word_2[j]:
            return order_map[c] < order_map[word_2[j]]
    return True

def isAlienSorted(words: list[str], order: str) -> bool:

    order_map = {c : index for index, c in enumerate(order)}
    for i in range(len(words) - 1):
        w1 = words[i]
        w2 = words[i+1]
        if not compare_words(w1, w2, order_map):
            return False

    return True

if __name__ == "__main__":

    if isAlienSorted(["hello","leetcode"], "hlabcdefgijkmnopqrstuvwxyz"):
        print("Test 1 completado")
    if not isAlienSorted(["word","world","row"], "worldabcefghijkmnpqstuvxyz"):
        print("Test 2 completado")
    if not isAlienSorted(["apple","app"], "abcdefghijklmnopqrstuvwxyz"):
        print("Test 3 completado")
    if isAlienSorted(["hello","hello"], "abcdefghijklmnopqrstuvwxyz"):
        print("Test 4 completado")
