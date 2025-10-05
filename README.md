# huffman-c
# Huffman Coding — Preorder Code Output (C++)

Build a Huffman Tree from a string of **distinct** characters `S` and their frequencies `f[]`, then print all Huffman codes in **preorder traversal** of the tree.

> Example  
> `S = "abcdef"`  
> `f = {5, 9, 12, 13, 16, 45}`  
> Output: `0 100 101 1100 1101 111`

---

##  Features

- Constructs an **optimal prefix-free** variable-length code using Huffman’s algorithm (greedy).
- Outputs codes in **preorder traversal**: visit node → left → right.
- Minimal, self-contained **C++** implementation using `priority_queue`.

---

##  Project Structure

