# Fractol-42

Draw fractals using MLX library in C

## Installation

# Clone the repo
```bash
git clone https://github.com/Prodaturu/fractol/ fractol_saikiran
```

# Navigate into the directory
```bash
cd fractol_saikiran
```

# Draw fractol

```bash
1. `./fractol m` for mandelbrot
```
```bash
2. `./fractol b` for burning ship
```
```bash
3. `./fractaol j real_val Imagnary_val` for julia
```

## Program Logic

The program follows the following logic:

- If more than one argument is provided:
  - Initialize the MLX library using `mlx_init`:
    - Parameters: width (int), height (int), title (string), resize (bool)
    - The parameters are pre-defined in the MLX library header file: WIDTH, HEIGHT, TITLE
    - The resize parameter is set to true to allow the window to be resizable
  - Allocate memory for a `t_fractal` structure using `malloc`
  - Cleanup & initialize `t_fractal` structure using `img_modhalu`:
    - Parameters: MLX library instance, `t_fractal` structure
    - If the initialization is successful:
      - Register the zoom hook using `mlx_scroll_hook`
      - Initialize the `t_fractal` struct using `ft_init`:
        - Parameters: `t_fractal` struct, argv, MLX lib instance, argc
        - Sets xmin, xmax, ymin, ymax values for Mandelbrot fractal
        - Sets xmin, xmax, ymin, ymax, cre & cim values for Julia fractal
        - If arguments are invalid, print error message & exit program 
      - Register the key hook using `mlx_key_hook`
      - Enter the main event loop using `mlx_loop`
      - Terminate the MLX library using `mlx_terminate`
  - Free the `t_fractal` structure using `free`
- Else, print an error message and return EXIT_FAILURE (i.e., 1)
