class Node {
    constructor() {
        this.children = {};
        this.isWordEnd = false;
    }
}

class Trie {

    constructor() {
        this.root = new Node();
    }

    insert(word) {
        let curr = this.root;
        for (let i = 0; i < word.length; i++) {
            let char = word[i];
            if (!(char in curr.children)) {
                curr.children[char] = new Node();
            }
            curr = curr.children[char];
        }
        curr.isWordEnd = true;
    }

    contains(word) {
        let curr = this.root;
        for (let i = 0; i < word.length; i++) {
            let char = word[i];
            if (!(char in curr.children)) {
                return false;
            }
            curr = curr.children[char];
        }
        return curr.isWordEnd;
    }

    startsWithPrefix(prefix) {
        let curr = this.root;
        for (let i = 0; i < prefix.length; i++) {
            let char = prefix[i];
            if (!(char in curr.children)) {
                return false;
            }
            curr = curr.children[char];
        }
        return true;
    }

    print() {
        let words = [];
        let search = function (node = this.root, string) {
            let len = Object.keys(node.children).length;
            if (Object.keys(node.children).length != 0) {
                for (let letter of Object.keys(node.children)) {
                    let n = node.children[letter];
                    search(node.children[letter], string.concat(letter));
                }
                if (node.isWordEnd) {
                    words.push(string);
                }
            } else {
                string.length > 0 ? words.push(string) : undefined;
            }
        }
        search(this.root, new String());
        return words;
    }

}

const trie = new Trie();
trie.insert('yo');
trie.insert('yok');
trie.insert('yp');
trie.insert('ypj');
console.log(trie.contains('yp'));
console.log(trie.startsWithPrefix('y'));
console.log(trie.print());