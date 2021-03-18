# Lab 5

## Task: Numbers

Various number systems can be related to each other hierarchically, e.g. complex number composed of to real numbers, and quaternion can be described through the pair of complex number.

- Write a class hierarchy for some numerical representations, so the following properties are observed:
  1. Each class has **one** explicitly defined encapsulated data member and **one** corresponding accessor function.
  2. Each class has an overwritten multiplication operation, `*`.

### Details

- Define a class `Real` that will store 1 real value that has following properties:
  - A constructor with one argument that initializes object with a real value.
  - An accessor function `GetReal` that returns a real value stored in an object of `Real` class.
  - An overwritten multiplication operation that adds a real value to the stored value in an object of `Real` class, and returns the results as an object of `Real` class.
- Define a class `Complex` that will store 2 real coefficients of a complex number that has following properties:
  - Derived from the `Real` class.
  - A constructor with two arguments that initializes object with a real values.
  - An accessor function `GetImaginary` that returns an imaginary value stored in an object of `Complex` class.
  - An overwritten multiplication operation that adds a real value to the stored values in an object of `Complex` class, and returns the results as an object of `Complex` class.
- Define a class `Surreal` that will store 3 real coefficients of a "surreal" number that has following properties:
  - Derived from the `Complex` class.
  - A constructor with tree arguments that initializes object with a real values.
  - An accessor function `GetSurreal` that returns an third/"surreal" value stored in an object of `Surreal` class.
  - An overwritten multiplication operation that adds a real value to the stored values in an object of `Surreal` class, and returns the results as an object of `Surreal` class.

### UML Class Diagram

<p style="width: 50%; margin-left: auto; display: block; margin-right: auto;">
<table cellpadding="3" border="1" style="width:fit-content; margin-bottom: 0px">
    <tbody><tr><th>Real</th></tr>
    <tr>
        <td>
            <tt>-</tt> re: Double <br>
        </td>
    </tr>
    <tr>
        <td>
            <u><tt>+</tt> Real( in a:Double )</u><br>
            <tt>+</tt> operator*( in v:Double ):Real<br>
        </td>
    </tr>
</tbody></table>
<!-- <span style='font-size:50px; writing-mode: vertical-rl; padding-left:50px;'>&#8701;</span> -->

![](gen.png)

<table cellpadding="2" border="1" style="width:fit-content; margin: -15px 0px 0px 0px">
    <tbody><tr><th>Complex</th></tr>
    <tr>
        <td>
            <tt>-</tt> im: Double <br>
        </td>
    </tr>
    <tr>
        <td>
            <u><tt>+</tt> Complex( in v:Double, in b:Double )</u><br>
            <tt>+</tt> operator*( in v:Double ):Complex<br>
        </td>
    </tr>
</tbody></table>
<!-- <span style='font-size:50px; writing-mode: vertical-rl; padding-left:50px;'>&#8701;</span> -->

![](gen.png)

<table cellpadding="3" border="1" style="width:fit-content; ; margin: -15px 0px 0px 0px">
    <tbody><tr><th>Surreal</th></tr>
    <tr>
        <td>
            <tt>-</tt> sur: Double <br>
        </td>
    </tr>
    <tr>
        <td>
            <u><tt>+</tt> Surreal( in a:Double, in b:Double, in c:Double )</u><br>
            <tt>+</tt> operator*( in v:Double ):Surreal<br>
        </td>
    </tr>
</tbody></table>

</p>

## Test

Press **Run** button to execute and test your program.

- Or run `make test` command in the command line to verify the correctness of your program.

## Submission

- Commit & push all changes that to the corresponding assignment repository on GitHub, using the **Repl.it** interface - **Version control** tab.
  - Make sure that you committed changes to following files:
    - `main.cpp`
- Submit the link of the assignment GitHub repository in the corresponding assignment submission the Blackboard.
  - Open corresponding assignment on the Blackboard
  - In **Assignment Submission** section, press **Write Submission** button
  - Paste your assignment repository link in the **Text Submission** box
  - Submit the assignment

### Before You Submit

You are required to test that your submission works properly before submission. Make sure that your program compiles without errors. Once you have verified that the submission is correct, you can submit your work.

### Coding Style

In any programming project, matching the existing coding style is important. Having different coding styles intermixed leads to confusion and bugs. Students are required to follow the particular existing coding style that maintains the indentation style in `.cpp` and `.h` files using spaces, not tabs.

In particular, pay close attention to function declarations and how the function name begins the line after the function return type. For helper functions which are limited in scope to a specific file, you must declare the function as `static` in the same file in which it is used.

*Indentation*: The indentation style for your work have to be 4 spaces. Many students are taught to use tabs for indentation, which can make code very hard to read, especially when there are several levels of indentation.

For additional information of C++ coding style see [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).

[gen]: data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAABCCAYAAAA2RtSlAAAABHNCSVQICAgIfAhkiAAAAdZJREFUaIHt2NtqFEEQxvHf7iYIgoJmEwO+hqAiGHc93PoOvoSnxKhXPoJXvoSIxjP4BHkCQRNFMQqChxUVL2oWwzIxM9O7eyH93U1PV9e/aqqrmyHrP9BRHGxq3El03sIdHMbzxLUaaQm/8BbzTRZIyUAbt7FVOP+BFwnr1dZJ/EYfF7GJhWk5n8EjPC6e5wqAa9MC6GOA3raxywXE4qSdz+KhiL61bXwBr00hCz18xbmSdysFxMRqoYP7eCp2wagOic9wdVIAPXxRHv1QKwVEd9zO21jDE//uH/N4g+VxA5wW0fcrzF3GOwlnxKjaovLXRA/YTWPPwikR/dkaNqsiC/tTnbfwQHS+2Rp2XbzHpVSAJXzHmQa2q+KkTKqFYc+v8u1HdQAfRZtupBP+nnhNdV0U5Fxdw7boes+k3Ru6+KBBLRzDT2nRD3UDG2qcER3cFdG3dplbRYtiS1Y+I47jm2aVv5Nu4pWRLJRV9owg3cI+nB8TwKYoxAu4NRwsS+8R0Xarbru94mY8qDh/Q+yuTzsB7CkWrap7WMeVGjafBXRplAPVoyF2ykARUV2V3WqmqgyQATJABsgAGSADZIAMkAEyQAbIABkgA4wD4KX4G5qV1Uh/ALyuUtegOZsNAAAAAElFTkSuQmCC "Genralization
