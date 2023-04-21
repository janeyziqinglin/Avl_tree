# Avl_tree
**Intro:**

Consider a scenario where a large dataset needs to be searched for a specific value using an index. Traditional data structures such as arrays and hash tables may not always provide an optimal solution for this problem. Arrays have a fixed size, and resizing them can be time-consuming and resource-intensive, while hash tables can suffer from collisions, leading to inefficient searching.

Binary search trees (BST) are another type of data structure that can be used for searching data, but the time complexity of a BST depends on its height. If the BST is balanced, the time complexity for searching, insertion, and deletion is O(log n), where n is the number of nodes in the tree. However, if the tree is imbalanced, such as a skewed tree, the time complexity can be as high as O(n), which is the same as that of an array. This makes BSTs unsuitable for handling large datasets with imbalanced or skewed data. In 1962, Adelson-Velskii and Landis (AVL) introduced AVL trees, which offered a solution to this problem [1].

AVL trees are a type of self-balancing binary search tree where the heights of the left and right subtrees of any node differ by at most one. The difference in the heights of the left and right subtrees is known as the balance factor b(v). The formula below shows the balance factor of a node v in an AVL tree [2].

b(v) = h(vr) - h(vl) (1)
where h(vr) and h(vl) are the heights of the right and left subtrees of node v.

The balance factor of nodes in an AVL tree may take on one of three possible values: -1, 0, or +1.
If the balance factor of a node is greater than one or less than negative one, then the tree is unbalanced and needs to be adjusted by performing rotations.

An example or rotation is display below. The resulting AVL tree has a height of 2 and is balanced, with the left and right subtrees of any node differing in height by at most one.

![test1](https://user-images.githubusercontent.com/105125897/233560691-a3d5293e-d0c1-41a3-839d-0764fd458590.gif). 


In AVL trees, there are four types of rotations that are used to maintain the balance of the tree: left-left (LL), left-right (LR), right-left (RL), and right-right (RR) rotations.

A left-left (LL) rotation is performed when the balance factor of a node is greater than one, and the height of the right subtree is greater than that of the left subtree. In an LL rotation, the left subtree of the node is rotated to the right, which results in the left child becoming the new root of the subtree.

A right-right (RR) rotation is performed when the balance factor of a node is less than negative one, and the height of the left subtree is greater than that of the right subtree. In an RR rotation, the right subtree of the node is rotated to the left, which results in the right child becoming the new root of the subtree.

A left-right (LR) rotation is performed when the balance factor of a node is greater than one, and the height of the left subtree is greater than that of the right subtree. In an LR rotation, a right-right (RR) rotation is first performed on the node's left child, followed by a left-left (LL) rotation on the node itself.

A right-left (RL) rotation is performed when the balance factor of a node is less than negative one, and the height of the right subtree is greater than that of the left subtree. In an RL rotation, a left-left (LL) rotation is first performed on the node's right child, followed by a right-right (RR) rotation on the node itself.

By performing these rotations, the balance factor of each node in the tree is maintained, ensuring that the heights of the left and right subtrees differ by at most one.

Table I: Comparison of time complexity between BST and AVL tree in both the worst case and average case.
| Operation | BST Average Case | BST Worst Case | AVL Average Case | AVL Worst Case |
|-----------|-----------------|----------------|------------------|----------------|
| Search | O(log n) | O(n) | O(log n) | O(log n) |
| Insertion | O(log n) | O(n) | O(log n) | O(log n) |
| Deletion | O(log n) | O(n) | O(log n) | O(log n) |

The average time complexity for both BST and AVL tree operations — search, insertion, and deletion are all O(log n). However, the worst-case time complexity for AVL tree remains O(log n), while BST tree gives O(n). This can be explained by the self-balancing feature of AVL trees. By maintaining a balanced height, AVL trees prevent the worst-case scenario that can occur in BST trees.

This report compare speed analysis for insertion and search between bst and avl, predict that avl search will be more efficient, while the insertion might have to withstand the cost of rotation.

This report is an analysis of the time complexity for insertion and search operations between BST and AVL trees. **The hypothesis is that AVL tree search is more efficient than BST search, because it prevents the tree from becoming imbalanced. However, the AVL tree insertion operation may be more computational costly due to the extra rotation cost to maintain the balanced height of the tree.**

In addition to speed analysis, this report also analyze the relationship between the number of swaps with number of nodes, as well as the order the nodes are given. **It is hypothesized that the number of swaps required for AVL tree insertion increases as the number of nodes in the tree increases, due to the self-balancing feature of AVL trees. It is expected that the number of swaps required for AVL tree insertion will be higher when the nodes are given in ascending order compared to when the nodes are given in a random order.** When the nodes are given in ascending order, the AVL tree becomes more imbalanced, leading to more rotations being required to maintain a balanced height. On the other hand, when the nodes are given in a random order, the AVL tree is more likely to be balanced, requiring fewer rotations and resulting in a lower number of swaps needed for insertion.

**Method:**

An AVL tree is implemented using the node structure. Each node stores a key, a pointer to the left child, a pointer to the right child, and a height value. The height value is updated during insertion and deletion operations to ensure that the tree remains balanced.

The main operations of an AVL tree are:
createNode, which creates a new node with the given key. getHeight, which returns the height of the given node. getBalanceFactor, which returns the balance factor of the given node, which is the difference in height of its left and right subtrees. updateHeight, which updates the height of the given node. rightRotate, which performs a right rotation on the given node. leftRotate, which performs a left rotation on the given node. rebalance, which rebalances the subtree rooted at the given node. insert, which inserts a new node with the given key into the tree. find, which finds the node with the given key in the tree, and lastly delete, which deletes the node with the given key from the tree.

**Results**

table of empirical data o(n) between bst and avl (average and worst)
Table II: Empirical data comparison of time complexity between BST and AVL tree in the worst case.
| Time | BSTInsert (s) | AVLInsert (s) | BSTSearch (s) | AVLSearch (s) |
|------|---------------|----------------|---------------|----------------|
| 10 | 0.000005 | 0.000011 | 0.000004 | 0.000003 |
| 100 | 0.000046 | 0.000557 | 0.000005 | 0.000004 |
| 1000 | 0.004692 | 0.016432 | 0.000028 | 0.000003 |
| 10000 | 0.485296 | 1.05001 | 0.000271 | 0.000003 |
| 25000 | 2.892409 | 5.661577 | 0.000631 | 0.000004 |
| 50000 | 11.566892 | 21.736761 | 0.001255 | 0.000002 |
| 100000 | 45.838785 | 84.836139 | 0.002523 | 0.000003 |

Table III: Empirical data comparison of number of swap in AVL tree using ascending order and random order.
| # of Nodes | Swaps (Ascending) | Swaps (Random) |
|------------|------------------|----------------|
| 10 | 69 | 23 |
| 100 | 1370 | 527 |
| 1000 | 17155 | 8056 |
| 10000 | 220959 | 90492 |
| 25000 | 579604 | 228289 |
| 50000 | 1202277 | 456409 |
| 100000 | 2506332 | 926339 |


Figure 1. Comparison of time complexity between BST and AVL tree for insert operation.
![insert](https://user-images.githubusercontent.com/105125897/233557351-fb3ea320-8b9b-4fa7-aef1-854c8ac7f75f.png)

Figure 2. Comparison of time complexity between BST and AVL tree for search operation.
![search](https://user-images.githubusercontent.com/105125897/233557360-77aef7e7-ad6b-4d3f-9d84-1e68d939e074.png)

Figure 3. Swap number over node number for AVL tree using ascending order and random order.
![swapnum](https://user-images.githubusercontent.com/105125897/233557371-2785bec3-cd32-479a-8551-ae4272035ccc.png)

**Discussion:**

Table II compares the time for insertion and search operations in BST and AVL trees for different numbers of nodes (10, 100, 1000, 10000, 25000, 50000, and 100000). Figure 1 and Figure 2 provides Graphical comparison for the empirical results.

Figure 2 compares the time for search operations in BST and AVL trees. The results show that for search operations, AVL trees outperform BSTs in terms of time complexity, and thereby align with our hypothesis that AVL tree search is more efficient than BST search.

Figure 1 compares the time for insertion operations in BST and AVL trees. For insertion operations, on the other hand, BST have faster average insert times than AVL trees. One possible reason for this is the self-balancing feature of AVL trees requires more rotations as the tree grows larger, resulting in a higher number of swaps and longer insertion times. This result is somewhat unexpected given that theoretically the worst-case time complexity for AVL tree is O(log n), while BST tree gives O(n). However, AVL tree insertion operations require more computational cost due to the rotation needed to maintain the balanced height of the tree, and thus, takes more time in insertion than BST tree.

Table III shows the number of swaps required for AVL tree insertion with varying numbers of nodes in ascending order or in random order. Figure 3 provides Graphical view for the empirical results.

Table III confirm the hypothesis that the number of swaps required for AVL tree insertion increases as the number of nodes in the tree increases.

As expected, Figure 3, shows that the number of swaps required for AVL tree insertion is higher when the nodes are given in ascending order compared to when the nodes are given in random order. In ascending order, the AVL tree becomes more imbalanced, leading to more rotations being required to maintain a balanced height. On the other hand, when the nodes are given in a random order, the AVL tree is more likely to be balanced, requiring fewer rotations and resulting in a lower number of swaps needed for insertion.

**Conclusion:**

The hypothesis of the report that AVL trees would outperform Binary Search Trees (BSTs) in terms of search times, particularly for imbalanced or skewed data. Additionally, it was hypothesized that the number of swaps required for AVL tree insertion would increase as the number of nodes in the tree increases. It was also expected that the number of swaps required for AVL tree insertion would be higher when the nodes were given in ascending order compared to when the nodes were given in a random order.

The results of the analysis confirm the hypothesis that AVL trees outperform BSTs in terms of search times since it prevent the worst-case scenario that can occur in traditional binary search trees. However, for insertion operations, the results show that BSTs can have faster average insert times than AVL trees for small datasets, which is rationalized by the extra cost of rotation.

The hypothesis that the number of swaps required for AVL tree insertion is also confirmed, with the analysis showing that the number of swaps increases as the number of nodes in the tree increases, and more swaps are required when nodes are given in ascending order compared to when they are given in a random order.

In conclusion, AVL trees offer several advantages over traditional binary search trees. They provide a reliable and efficient solution for searching and managing large datasets with imbalanced or skewed data. AVL trees offer faster search times than traditional binary search trees with O(log n) time complexity for search, insertion, and deletion operations, where n is the number of nodes in the tree. Additionally, the self-balancing feature of AVL trees minimizes the time complexity of operations, making them a powerful tool for handling large datasets.However, AVL trees are not perfect and may not be the best choice in all scenarios. They can be expensive in scenarios where insertions are frequent and searches are infrequent. In such cases, other self-balancing binary search trees such as Red-Black trees  B-trees and B+ trees may be more suitable. Therefore, it is important to consider the specific use case and data requirements before choosing AVL trees as the optimal solution.[3].

**Citation:**

[1]Adel'son-Vel'skiy, G.M., and Landis, Ye.M. An algorithm for the organization of information. Doklady Akad. Nauk USSR Moscos 16, No. 2 (1962), 263-266. Also available in translation as U.S. Dept. of Commerce OTS, JPRS 17,137, Washington, D.C., and as NASA Document N63-11777.

[2] Mahdi Amani (2018) Gap terminology and related combinatorial properties for AVL trees and Fibonacci-isomorphic trees, AKCE International Journal of Graphs and Combinatorics, 15:1, 14-21, DOI: 10.1016/j.akcej.2018.01.019

[3]Gupta, G. K. (1984). Self-assessment procedure XIII: a self-assessment procedure dealing with binary search trees and B-trees. Communications of the ACM, 27(5), 435-443.
