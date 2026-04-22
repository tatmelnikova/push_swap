*This project has been created as part of the 42 curriculum by skorenev <skorenev@student.codam.nl>,  tkazmina <tkazmina@student.codam.nl>*
## Description
Push_swap is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations. The goal is not only to achieve a correctly sorted result but to do so with the smallest possible number of moves, encouraging efficient algorithm design and optimization.

In this implementation, multiple sorting strategies are used depending on the size and nature of the input:

Bubble sort is applied for datasets with low disorder. Its simplicity makes it suitable when the elements are almost sorted.
Chunk sort is used for inputs with an average disorder metrics. The idea is to divide the dataset into smaller “chunks” and push elements between stacks in a controlled way, gradually organizing them. This approach improves efficiency by reducing unnecessary operations and structuring the sorting process.
Radix sort is implemented for datasets with high disorder. It leverages the binary representation of numbers to sort elements bit by bit, making it highly efficient for handling big inputs within the constraints of push_swap operations.

By combining these algorithms, the program adapts to different input types and achieves optimized performance.

## Instructions

**1. Compiling the library**

To compile the library, run:

```shell
$ cd path/to/push_swap && make
```
**2. Usage with different argument sets**

Avaliable flags are:
strategy selector: **--simple, --medium, --complex**

optional flag: **--bench**

Usage example:

```shell
ARG="4 67 3 87 23"; ./push_swap --complex --bench $ARG
```

Usage example with checker: 

```shell
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
```
## Resources

- [cppreference.com](https://en.cppreference.com/w/c)
- [man pages online — Linux man-pages project](https://man7.org/linux/man-pages/)
- [wikipedia.org sorting algorithms overview](https://en.wikipedia.org/wiki/Sorting_algorithm)

### AI usage
- Documentation for code was written with AI help

## Relization details

**Bubble sort**

Bubble sort was chosen for handling almost ordered datasets due to its simplicity, predictability, and low implementation overhead. In the context of the push_swap project, where the number of elements can be minimal (e.g., 2–5 values), the performance drawbacks typically associated with bubble sort become negligible.

For such inputs, the algorithm’s straightforward compare-and-swap approach translates well into push_swap operations, making it easy to implement and debug without introducing unnecessary complexity. More advanced algorithms would not provide meaningful performance gains at this scale, while potentially increasing the number of instructions or the risk of errors.


**Chunk sort**

Chunk sort was chosen for datasets with medium disorder because it offers a balanced approach between simplicity and efficiency within the constraints of the push_swap project. While simpler algorithms become inefficient as input size grows, and radix sort may be unnecessary or overly structured for mid-range inputs, chunk sort provides a practical middle ground.

The core idea is to divide the dataset into smaller segments, or “chunks,” based on value ranges. Elements are then pushed to the auxiliary stack in groups, allowing partial ordering to be established early in the process. This reduces the need for excessive rotations and comparisons, leading to a more controlled and efficient sequence of operations.

Overall, chunk sort is well-suited for medium-sized inputs because it reduces complexity compared to naive methods while avoiding the overhead of more advanced algorithms, resulting in an efficient and adaptable sorting strategy.

**LSD Radix sort**

Radix sort was chosen for unordered datasets because it provides a highly efficient and predictable way to sort integers within the constraints of the push_swap project. Unlike comparison-based algorithms, radix sort operates on the binary representation of numbers, allowing the sorting process to be broken down into simple, repeatable steps that map well to the allowed stack operations.

The main idea of the algoritm is distribution of the elements between the two stacks based on the value of individual bits, starting from the least significant bit and progressing to the most significant. This avoids complex comparisons and reduces the overall number of operations, which is a key requirement of the project.

Another advantage is its consistent time complexity. 

## Learners contribution

*tkazmina*

LSD radix sort implementation

Bench output

Memory management

Base stack operations

*skorenev*

Bubble sort implementation

Chunk sort implementation

Input handling

Base stack operations



<!-- A README.md file must be provided at the root of your Git repository. Its purpose is
to allow anyone unfamiliar with the project (peers, staff, recruiters, etc.) to quickly understand what the project is about, how to run it, and where to find more information on the topic.
The README.md must include at least:
• The very first line must be italicized and read: This project has been created as part
of the 42 curriculum by <login1>[, <login2>[, <login3>[...]]].
• A “Description” section that clearly presents the project, including its goal and a brief overview. 
• An “Instructions” section containing any relevant information about compilation, installation, and/or execution.
• A “Resources” section listing classic references related to the topic (documentation, articles, tutorials, etc.), as well as a description of how AI was used — specifying for which tasks and which parts of the project.
➠ Additional sections may be required depending on the project (e.g., usage
examples, feature list, technical choices, etc.).
Any required additions will be explicitly listed below.
• A detailed explanation and justification of the algorithms selected for this project must also be included. 
The repository must clearly indicate both learners’ contributions in the README.md
file.-->
