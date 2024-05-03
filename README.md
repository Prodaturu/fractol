<a name="readme-top"></a>
<div align="center">
  <!-- Logo -->
  <a href="https://github.com/Prodaturu/fractol">
  <img src="README_files/logo.png" alt="Logo" width="90" height="90">
  </a>

  <!-- Project Name -->
  <h1>Fractol Project</h1>

  <!-- Short Description -->
  <p align="center">
	  <b>Fractol 42Heilbronn</b><br>
	  For further information about 42cursus and its projects, please refer to <a href="https://www.42heilbronn.de/en/"><b>42 Heilbronn</b></a>.
  </p>

  <!-- Badges -->
  <p>
    <img src="https://img.shields.io/badge/score-125%20%2F%20100-success?style=for-the-badge" />
    <img src="https://img.shields.io/github/repo-size/Prodaturu/fractol?style=for-the-badge&logo=github">
    <img src="https://img.shields.io/github/languages/count/Prodaturu/fractol?style=for-the-badge&logo=" />
    <img src="https://img.shields.io/github/languages/top/Prodaturu/fractol?style=for-the-badge" />
    <img src="https://img.shields.io/github/last-commit/Prodaturu/fractol?style=for-the-badge" />
  </p>

  <h3>
      <a href="#-about-project">📜 About Project</a>
    <span> · </span>
      <a href="#-fractals-list">📑 Fractals List</a>
    <span> · </span>
      <a href="#-controls">🎮 Controls</a>
    <span> · </span>
      <a href="#-usage">👨‍💻 Usage</a>
    <span> · </span>
      <a href="#-screenshots">🌄 Screenshots</a>
  </h3>
</div>

---

## 📜 About Project

> One of the first graphical projects at 42 School, fract-ol generates beautiful fractals from the complex numbers of \
> an iterative mathematical construct. A fractal is a fragmented geometrical figure that infinitely repeats itself at smaller scales. 
> This project uses the school's graphical library, MLX42.

For detailed information, refer to the [**subject of this project**](readme_files/fractol_subject.pdf).

	🚀 TLDR: The fract-ol project is one of the three "beginner" graphical projects of the 
 		 cursus. It teaches you about using graphic library, advanced math, and more.


> [!NOTE]  
> Because of 42 School norm requirements:
> * Each function can't have more than 25 lines of code.
> * All variables are declared and aligned at the top of each function.
> * Project should be created just with allowed functions otherwise it's cheating.


## 📑 Fractals List

The program supports these fractal sets:

| Name              | Formula                                                                                            |
|:-----------------:|:--------------------------------------------------------------------------------------------------:|
| Mandelbrot        | $z_{n+1} = z_n^2 + c, z_0 = 0$                                                                     |
| Julia             | $z_{n+1} = z_n^2 + c, z_0 = c$                                                                     |
| Burning Ship      | $z_{n+1} = abs(z_n^2) + c, z_0 = 0$                                                                |

## 🎮 Controls

The program supports the following controls:

| Key           | Description                             |
|:-------------:|:---------------------------------------:|
| ESC           | Close the program window                |
| Mouse Scroll  | Zoom in and out of the fractal          |
| ⬆️ ⬇️ ⬅️ ➡️     | Change the viewpoint                    |

## 👨‍💻 Usage
### Requirements

The program is written in C language and thus needs the **gcc compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the program**

To compile the program, run:

```shell
$ cd path_to_fractol && make
```

**2. How to run the program**

Run the executable too see the help message:
```shell
./fractol
```

Or run with some supported fractal:
```shell
./fractol m
```

## Program Logic

The program follows the logic below:

### If more than one argument is provided:

1. **Initialize the MLX library** using `mlx_init`:
   - Parameters: `width` (int), `height` (int), `title` (string), `resize` (bool)
   - The parameters are pre-defined in the MLX library header file: `WIDTH`, `HEIGHT`, `TITLE`
   - The `resize` parameter is set to true to allow the window to be resizable

2. **Allocate memory** for a `t_fractal` structure using `malloc`

3. **Cleanup & initialize `t_fractal` structure** using `img_modhalu`:
   - Parameters: MLX library instance, `t_fractal` structure
   - If the initialization is successful:
     - Register the zoom hook using `mlx_scroll_hook`
     - Initialize the `t_fractal` struct using `ft_init`:
       - Parameters: `t_fractal` struct, `argv`, MLX lib instance, `argc`
       - Sets `xmin`, `xmax`, `ymin`, `ymax` values for Mandelbrot fractal
       - Sets `xmin`, `xmax`, `ymin`, `ymax`, `cre` & `cim` values for Julia fractal
       - If arguments are invalid, print error message & exit program 
     - Register the key hook using `mlx_key_hook`
     - Enter the main event loop using `mlx_loop`
     - Terminate the MLX library using `mlx_terminate`

4. **Free the `t_fractal` structure** using `free`

### Else

Print an error message and return `EXIT_FAILURE` (i.e., 1)
