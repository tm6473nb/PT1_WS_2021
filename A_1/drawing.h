#ifndef DRAWING_H_
#define DRAWING_H_

#include <cairo/cairo.h>
#include <gtk/gtk.h>

extern GtkWidget *drawing_gtk_window;
extern GtkWidget *drawing_gtk_area;
extern cairo_t *drawing_cairo;

void drawing_static_init(int, int);
void drawing_static_write_png(char*);
void drawing_dynamic_init();

void drawing_log_enable();
void drawing_log_disable();

void drawing_dynamic_register_draw(void (*)());
void drawing_dynamic_register_key_pressed(void (*)(char*, int));
void drawing_dynamic_register_key_released(void (*)(char*, int));
void drawing_dynamic_register_mouse_pressed(void (*)(int, int, int));
void drawing_dynamic_register_mouse_released(void (*)(int, int, int));
void drawing_dynamic_register_mouse_moved(void (*)(int, int));

void drawing_clear(double, double, double);
void redraw();

#endif
