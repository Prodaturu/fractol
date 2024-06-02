/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 08:10:52 by sprodatu          #+#    #+#             */
/*   Updated: 2024/04/19 13:19:21 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

/** helper functions to code
 * 
 * giyi_mandel: Mandelbrot fractal hook
 * 
 * giyi_julia: Julia fractal hook
 * 
 * ft_atof: Convert a string to a double
 * 	- written in decimals.c
 * 
*/

/*
old implementation:-
void	moving(mlx_key_data_t keydata, void *param)
{
	t_fractal	*f;
	double		dx;
	double		dy;

	f = (t_fractal *)param;
	dx = (f->xmax - f->xmin) * 0.1;
	dy = (f->ymax - f->ymin) * 0.1;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		f->ymin += dy;
		f->ymax += dy;
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		f->ymin -= dy;
		f->ymax -= dy;
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		f->xmin += dx;
		f->xmax += dx;
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		f->xmin -= dx;
		f->xmax -= dx;
	}
}
*/

/** zooming documentation
 * Zooms the fractal by adjusting the x and y coordinates.
 * 
 * @param x_diff The difference in the x coordinate.
 * @param y_diff The difference in the y coordinate.
 * @param param A pointer to the mlx_t structure and t_fractal structure.
 */

/** function_name: zooming
 * Zooming in or out on the fractal image
 * 
 * If y_diff is positive, the image is zoomed in
 * 	- the xmin, xmax, ymin, ymax values are updated
 * if y_diff is negative, the image is zoomed out
 * 	- the xmin, xmax, ymin, ymax values are updated
 * giyali is set to 1 to draw the fractal
*/

/**
 * *zooming panitiru*
 * mana fractal image ni zoom in zoom out chestam
 * y_diff positive unte zoom in ledante zoom out
 *
 * param ni mlx_t struct ki typecast chesi mlx ki pass chestam
 * param ni t_fractal struct ki typecast chesi f ki pass chestam
 * dini dwara mmana mlx_t inka t_fractal structs ni access avutam
 * manaki 25% zoom ante 0.25
 * x_delta avasaram ledu kabati 0 ki multiply chestam
 * zoom_in ante y_delta +ve ante change 1
 * alage zoom_out ante y_delta -ve ante change -1
 * Ipudu zoon in scenario tiskundam:
 * 		Zoom in ante xmin xmax ymin ymax center ki daggaraki move avutayi
 * 		ante manam xmax ni tagiyali  
 */

void	sub_zooming(t_fractal *f, double change, double xpos, double ypos)
{
	f->xmin = xpos + (f->xmin - xpos) * change;
	f->xmax = xpos + (f->xmax - xpos) * change;
	f->ymin = ypos + (f->ymin - ypos) * change;
	f->ymax = ypos + (f->ymax - ypos) * change;
}

void	zooming(double x_diff, double y_diff, void *param)
{
	t_fractal	*f;
	double		change;
	float		xpos;
	float		ypos;

	x_diff = 0.0;
	change = 0.0;
	xpos = 0.0;
	ypos = 0.0;
	f = (t_fractal *)param;
	mlx_get_mouse_pos(f->mlx, &f->xpos, &f->ypos);
	if (f->xpos >= 0 && f->ypos >= 0 && f->xpos < (int32_t)f->bomma->width
		&& f->ypos < (int32_t)f->bomma->height)
	{
		xpos = (double)f->xpos * (f->xmax - f->xmin) / (double)WIDTH + f->xmin;
		ypos = (double)f->ypos * (f->ymax - f->xmin) / (double)HEIGHT + f->ymin;
	}
	if (y_diff > 0)
		change = 0.9;
	else if (y_diff < 0)
		change = 1.1;
	sub_zooming(f, change, xpos, ypos);
	f->giyali = 1;
}

/** fract_modalu documentation
 * 
 * @brief Initialize the t_mandel structure based on command-line arguments.
 *
 * function initializes t_mandel struct based on the argv.
 * If argv[1] is 'm' and there is only one argument, 
 * 		sets the xmin, xmax, ymin, ymax values for Mandelbrot fractal.
 * If argv[1] is 'j' and there are 3 arguments, 
 * 		sets the xmin, xmax, ymin, ymax, cre, cim values for the Julia fractal.
 * If arguments are un-valid,
 * 		it prints an error message and exits the program.
 *
 * @param f A pointer to the t_fractal structure.
 * @param c An array of strings containing the command-line arguments.
 * @param mlx The MLX library instance.
 * @param argc The number of command-line arguments.
 * 
 * @return void
 * 
 * @mlx_loop_hook: Register the Mandelbrot or Julia hook.
 * @write: Print an error message.
 * @exit: Exit the program.
 */

/** function name: fract_modalu
 * Initial values for image size in t_fractal struct are set
 * 
 * Check argv for which type of fractal (i.e madelbrot or julia)
 * 	- if argv[1] is m its mandelbrot and j is julia
 * when mandel/julia and has right no of args for the type
 * 	- choose default size of image using xmin, xmax, ymin, ymax
 * 
 * if its not both or has wrong no of args
 * 	- print error message and exit
*/

/**
 * *fract_modalu panitiru*
 * t_fractal ki start avtune undalisina bomma kolatalu istham
 * 
 * sarina argv unda leda inka madelbrt ah julia na chustam
 * 	- unte giyali ni 1 chestam
 * 	- argv[1] m ante madelbrot, j ante julia
 * ani sariga unte 
 * 	- bomma ki oka default kolatalu istam
 * 	- xmin, xmax, ymin, ymax (cre, cim) pani adi
 * 	- tarvata ml_loop_hook lo register chestam
 * 		- (mandelbrot/julia) fn ni register chestam
 * 		- e hook tho image ni display chestam
 * 		- e hook lo register chestunte
 * 			- mouse scroll ki zoom, key press ki color change
 * edina sariga ledu ante (tappu args o leda e rendu fractals kani apudu)
 * 	- error message print chestam
*/

void	fract_modalu(t_fractal *f, char **argv, void *mlx, int argc)
{
	if (*argv[1] != 'm' && *argv[1] != 'j' && *argv[1] != 'b')
		return (ft_putstr("Use: ./fractol [m | j ...]\n"), exit(EXIT_FAILURE));
	else
		f->giyali = 1;
	if (*argv[1] == 'j' && argc == 4)
	{
		f->xmin = -1.5;
		f->xmax = 1.5;
		f->ymin = -1.5;
		f->ymax = 1.5;
		f->cre = ft_atof(argv[2]);
		f->cim = ft_atof(argv[3]);
		mlx_loop_hook(mlx, giyi_julia, f);
	}
	else if (*argv[1] == 'm' && argc == 2)
		mandel_is_hooked(mlx, f);
	else if (*argv[1] == 'b' && argc == 2)
		burn_the_ship(mlx, f);
	else
		return (ft_putstr("incorrect arguments\n"), exit(EXIT_FAILURE));
}

/**
 ** img_modhalu
 * 
 * @brief Initialize the MLX library and create a new image.
 * 
 * 	If the initialization or image creation fails,
 * 		it closes the window
 * 			errno is set to appropriate error code
 * 			returns EXIT_FAILURE.
 * 
 *  new image with said width, height is made using mlx_new_image
 * 
 * 	if the image is not created successfully
 * 		it closes the window
 * 		errno is set to appropriate error code
 * 		returns EXIT_FAILURE.
 * 
 * 	mlx_image_to_window is used to display the image in the window)
 * 	If the image is not displayed successfully (i.e. return -1)
 * 		it closes the window
 * 		errno is set to appropriate error code
 * 		returns EXIT_FAILURE.
 *
 * Return 1 if successful
 * 
 * @param mlx The mlx_t structure to initialize.
 * @param f The t_fractal structure containing the image.
 * @return 1 if successful, EXIT_FAILURE otherwise.
 */

/**
 * *img_modhalu panitiru*
 * 
 * MLX library initialize chesundo ledo chustam
 * lekapote error message print chestam
 * 
 * new image create chestam idi struct to bomma var lo store chestam
 * ipudu e image create avakapoina leda bomma var lo store avakapoina
 * window close chesi, saraina error code set chesi, EXIT_FAILURE return chestam
*/

int	img_modhalu(void *mlx, t_fractal *f)
{
	if (!mlx)
		return (mlx_strerror(mlx_errno), EXIT_FAILURE);
	f->bomma = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!f->bomma || mlx_image_to_window(mlx, f->bomma, 0, 0) == -1)
		return (mlx_close_window(mlx), mlx_strerror(mlx_errno), EXIT_FAILURE);
	return (1);
}

/**
 ** main documentation
 * 
 * @brief The main function of the fractol program.
 *
 * entry point of the program. It initializes the MLX library,
 * allocates memory for the t_fractal structure
 * sets up the necessary hooks and event handlers
 * then enters main event loop using mlx_loop()
 * terminates the MLX library when the loop exits.
 *
 * @param argc number of command-line arguments.
 * @param argv array of strings containing command-line arguments.
 *
 * @return EXIT_SUCCESS (0) if the program runs successfully,
 * 		or EXIT_FAILURE (1) if there is a error or no command-line arguments.
 * 
 * @mlx: The MLX library instance
 * @f:  The t_fractal structure for storing fractal data
 * 
 * @mlx_init: Initialize the MLX library
 * 		-> parameters:- width, height, title, resize
 * 		-> returns a pointer to the MLX library instance
 * 
 * @malloc: Allocate memory for the t_fractal structure
 * 
 * @img_modhalu: Initialize the MLX library and create a new image
 * 		-> parameters:- MLX library instance, t_fractal structure
 * 		-> returns 1 if successful, EXIT_FAILURE otherwise
 * 
 * @mlx_scroll_hook: Register the zoom hook
 * 		-> parameters:- MLX library instance, zoom (cust-fn), t_fractal structure
 * 
 * @ft_init: Initialize the t_fractal structure
 * 		-> parameters:- t_fractal struct, argv, MLX lib instance, argc
 * 
 * @mlx_key_hook: Register the key hook
 * 		-> parameters:- MLX library instance, key function, t_fractal structure
 * 
 * @mlx_loop: Enter the main event loop
 * 		-> parameters:- MLX library instance
 * 
 * @mlx_terminate: Terminate the MLX library
 * 		-> parameters:- MLX library instance
 * 
 * @free: Free the allocated memory for the t_fractal structure
 */

/**
 * *main logic*
 * 
 * if more than one argument is provided
 * 		Initialize the MLX library
 * 			-> mlx_init (mlx)
 * 		Allocate memory for a t_fractal structure
 * 			-> malloc and return pointer to allocated memory
 * 		cleanup & initialize  t_fractal structure
 * 			-> img_modhalu, initializes & cleansup t_fractal struct
 * 			-> parameters:- MLX library instance, t_fractal structure
 * 				-> initializes the t_fractal structure
 * 				-> creates a new image
 * 				-> checks if the image was created successfully
 * 				-> checks if the MLX library instance is initialized successfully
 * 		Free the t_fractal structure
 * else
 * 		Print an error message
 * 		Return EXIT_FAILURE i.e 1
 */

/**
 * *Pani tiru* (telugu explanation with ascii characters)
 * 
 * Main function program ki entry point
 * 
 * First manam argumments correct ga unaya leda chustam
 * 		tappu ga unte error message print chestam
 * 
 * MLX library ni initialize chestam (mlx_init)
 * Manam fractal create cheyadanki information store cheyali,
 * anduku t_fractal struct ni allocate chestam
 * 
 * ipudu oka image window create chestam (img_modhalu)
 * img_modhalu fn oka image create chestundi
 * 
 * image create ayunte next steps chestam
 * scroll event handler fn ni register chestam (mlx_scroll_hook)
 * fractal data ni initialize chestam (fract_modalu)
 * key press event handler fn ni register chestam (mlx_key_hook)
 * main event loop lo enter avtam (mlx_loop)
 * MLX library ni terminate chestam (mlx_terminate)w
 * antha correct ayindi ani return chestam
*/

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	t_fractal	*f;

	if (argc <= 1)
		return (ft_putstr_fd("Use: ./fractol [m | j | n]\n", 2), EXIT_FAILURE);
	mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	f = (t_fractal *)malloc(sizeof(t_fractal));
	f->mlx = mlx;
	if (!f)
		return (EXIT_FAILURE);
	if (img_modhalu(mlx, f))
	{
		mlx_scroll_hook(mlx, zooming, f);
		fract_modalu(f, argv, mlx, argc);
		mlx_key_hook(mlx, moving, f);
		mlx_loop(mlx);
		mlx_terminate(mlx);
		return (EXIT_SUCCESS);
	}
	else
	{
		free(f);
		return (EXIT_FAILURE);
	}
}

/**
 * @logic:
 * 
 * if more than one argument is provided
 * 		Initialize the MLX library
 * 			-> mlx_init, mlx lib-fn is used to initialize library
 * 			-> parameters:- width(int), height(int), title(string), resize(bool)
 * 				-> It takes the width, height, and title of the window
 * 				-> It returns a pointer to the MLX library instance
 * 				-> The parameters are pre-defined in MLX library header file
 * 					-> WIDTH, HEIGHT, TITLE
 * 				-> The resize parameter is set to true
 * 					-> true: allows the window to be resized
 * 					-> false: does not allow the window to be resized
 * 					-> As we want the window to be resizable, we set it to true
 * 				-> mlx_init returns a pointer to the MLX library instance
 * 		Allocate memory for a t_fractal structure
 * 			-> malloc, standard lib-fn is used to allocate memory
 * 			-> this t_madel structure is used to store fractal data
 * 			-> sizeof(t_fractal) is the size of the t_fractal structure
 * 			-> malloc returns a pointer to the allocated memory
 * 			-> This is defined in the fractol.h header file
 * 		cleanup & initialize  t_fractal structure
 * 			-> img_modhalu cust-fn initializes & cleansup t_fractal struct
 * 			-> parameters:- MLX library instance, t_fractal structure
 * 				-> initializes the t_fractal structure
 * 				-> creates a new image
 * 				-> checks if the image was created successfully
 * 				-> checks if the MLX library instance is initialized successfully
 * 					-> It returns 1 if the initialization is successful
 * 					-> It returns EXIT_FAILURE if there is an error
 * 						-> EXIT_FAILURE: indicates there is an error
 * 			-> If the initialization is successful
 * 				-> Register the zoom hook
 * 					-> mlx_scroll_hook, MLX lib-fn is used to register the zoom hook
 * 					-> parameters:- MLX library instance, zoom (cust-fn), t_fractal structure
 * 						-> registers the zoom hook
 * 						-> calls the zoom function when the mouse is scrolled
 * 				-> Initialize the t_fractal struct
 * 					-> ft_init, cust-fn is used to initialize the t_fractal structure
 * 					-> parameters:- t_fractal struct, argv, MLX lib instance, argc
 * 						-> initializes t_fractal struct based on command-line arguments
 * 						-> sets xmin xmax ymin ymax values for Mandelbrot fractal
 * 						-> sets xmin xmax ymin ymax cre & cim values for Julia fractal
 * 						-> if arguments are un-valid print error_msg & exit program 
 * 				-> Register the key hook
 * 					-> mlx_key_hook, MLX lib-fn is used to register the key hook
 * 					-> parameters:- MLX library instance, key function, t_fractal structure
 * 						-> It registers the key hook
 * 						-> It calls the key function when a key is pressed
 * 				-> Enter the main event loop
 * 					-> mlx_loop, MLX lib-fn is used to enter the main event loop
 * 					-> parameters:- MLX library instance
 * 						-> It enters the main event loop
 * 						-> It calls the registered hooks and event handlers
 * 				-> Terminate the MLX library
 * 					-> mlx_terminate, MLX lib-fn is used to terminate the MLX library
 * 					-> parameters:- MLX library instance
 * 						-> It terminates the MLX library
 * 		Free the t_fractal structure
 * 			-> free, standard lib-fn is used to free the allocated memory
 * 			-> It frees the memory allocated for the t_fractal structure
 * else
 * 		Print an error message
 * 		Return EXIT_FAILURE i.e 1
*/

/**
 * old zooming function
 * 
// void	zooming(double x_diff, double y_diff, void *param)
// {
// 	mlx_t		*mlx;
// 	t_fractal	*f;
// 	int			zoom;

// 	mlx = (mlx_t *)param;
// 	f = (t_fractal *)param;
// 	zoom = 0.25;

// 	if (y_diff > 0)
// 	{
// 		f->xmin += x_diff * zoom;
// 		f->xmax -= x_diff * zoom;
// 		f->ymin += y_diff * zoom;
// 		f->ymax -= y_diff * zoom;
// 	}
// 	else if (y_diff < 0)
// 	{
// 		f->xmin -= x_diff * zoom;
// 		f->xmax += x_diff * zoom;
// 		f->ymin -= y_diff * zoom;
// 		f->ymax += y_diff * zoom;
// 	}
// 	f->giyali = 1;
// }
*/
