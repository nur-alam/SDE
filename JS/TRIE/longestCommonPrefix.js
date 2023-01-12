
let ALPHABET_SIZE = 26;

class TrieNode {
    constructor() {
        this.parent = null;
        this.childCount = 0;
        this.isEndOfWord = false;
        this.children = new Array(ALPHABET_SIZE);
        // for (let i = 0; i < ALPHABET_SIZE; i++)
        //     this.children[i] = null;
    }
}

class Trie {
    constructor() {
        this.root = new TrieNode();
    }

    insert(word) {
        let curr = this.root;
        for (let i = 0; i < word.length; i++) {
            let index = word[i].charCodeAt(0) - 'a'.charCodeAt(0);
            if (curr.children[index] == null) {
                curr.children[index] = new TrieNode();
                curr.children[index].parent = curr;
                curr.childCount++;
            }
            curr = curr.children[index];
        }
        curr.isEndOfWord = true;
    }

    search(word) {
        let curr = this.root;
        let i, index, len = word.length;
        for (i = 0; i < len; i++) {
            index = word[i].charCodeAt(0) - 'a'.charCodeAt(0);
            if (curr.children[index] == null)
                return false;
            curr = curr.children[index];
        }
        return curr.isEndOfWord;
    }

    isEmpty(root) {
        for (let i = 0; i < ALPHABET_SIZE; i++) {
            if (root.children[i] != null)
                return false;
        }
        return true;
    }

    remove(root, word, depth = 0) {
        if (root == null)
            return null;
        if (depth == word.length) {
            if (root.isEndOfWord)
                root.isEndOfWord = false;
            if (this.isEmpty(root))
                return null;
            return root;
        }
        let index = word[depth].charCodeAt(0) - 'a'.charCodeAt(0);
        root.children[index] = this.remove(root.children[index], word, depth + 1);
        if (this.isEmpty(root) && root.isEndOfWord == false) {
            root = null;
        }
        return root;
    }

    lcp(word) {
        let ans = '';
        let curr = this.root;
        for (let i = 0; i < word.length; i++) {
            let ch = word[i];
            let index = word[i].charCodeAt(0) - 'a'.charCodeAt(0);
            if (curr.childCount == 1) {
                ans += ch;
                curr = curr.children[index];
            } else {
                break;
            }
            if (curr.isEndOfWord)
                break;
        }
        return ans;
    }

}

const trie = new Trie();
// console.log(trie.root);
// trie.insert('abc');
// trie.insert('ab');
// trie.insert('cad');
// trie.insert('ca');
// console.log(trie.lcp());
// trie.remove(trie.root, 'abc', 0);
// console.log(trie.search('abc'));
let strArr = ['ab', 'abc', 'abd', 'abf'];
strArr.forEach((str) => {
    trie.insert(str);
});
console.log(trie.lcp(strArr[0]));
console.log('ABC'.charCodeAt(2));