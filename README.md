<!-- PROJECT START -->
# Closest pair of points
Implementing an *O(n lg n)* algorithm to determine the closest pair of points in a provided set of points.

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#divide">Divide</a></li>
        <li><a href="#conquer">Conquer</a></li>
        <li><a href="#combine">Combine</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#help">Help</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About the project

The objective of this program is to implement an *O(n lg n)* algorithm to determine the closest pair of points in a provided set of points *P* 
inside the two-dimensional plane.

“Closest” refers to the usual euclidean distance. 

This problem has applications in, for example, traffic-control systems. A system for controlling air or sea traffic might need to identify the 
two closest vehicles in order to detect potential collisions.

To solve this, a divide-and-conquer algorithm will be implemented, which uses *O(n lg n)* time. The program carries out the divide-and-conquer 
paradigm as follows.

### Divide
The set of points is divided into two sets, where each of the x-coordinates and y-coordinates are allocated accordingly to where their 
point was allocated.

### Conquer
After dividing the set of points into two, make two recursive calls to find the closest pair of points in each of the resulting subsets.

### Combine
The closest pair can now either be a pair found be the previous two recursive calls, or will be a pair where one point lies in one of the
two subsets and one point lies in the other.

<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites

Things you need to use the software.
* MacOS
* Xcode

### Installation

Clone this repo.
   ```sh
   git clone https://github.com/vmthanh-bi/Closest-pair-of-points.git
   ```

<!-- Help -->
## Help

See the [open issues](https://github.com/vmthanh-bi/Closest-pair-of-points/issues) for a list of proposed features (and known issues).

<!-- CONTACT -->
## Contact

Tony Vu - [@vmthanh.bi](https://github.com/vmthanh-bi) - vmthanh.bi@gmail.com

Project Link: [https://github.com/vmthanh-bi/Closest-pair-of-points](https://github.com/vmthanh-bi/Closest-pair-of-points)

<!-- MARKDOWN LINKS & IMAGES -->

