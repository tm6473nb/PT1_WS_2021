#include "drawing.h"
#include <stdio.h>

void (*drawing_draw)();
void (*drawing_mouse_pressed)(int, int, int);
void (*drawing_mouse_released)(int, int, int);
void (*drawing_mouse_moved)(int, int);
void (*drawing_key_pressed)(char*, int);
void (*drawing_key_released)(char*, int);

GtkWidget *drawing_gtk_window;
GtkWidget *drawing_gtk_area;
cairo_t *drawing_cairo;
cairo_surface_t *drawing_cairo_surface;
int drawing_log = 0;

void drawing_log_enable()
{
  drawing_log = 1;
}

void drawing_log_disable()
{
  drawing_log = 0;
}

void log_to_console(const char *format, ...)
{
  if (drawing_log)
  {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
  }
}

void redraw() 
{
  gtk_widget_queue_draw(drawing_gtk_area);
}

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr)
{
  cairo_set_source_rgb(cr, 0, 0, 0.5);
  cairo_paint(cr);
  drawing_cairo = cr;

  if (drawing_draw != NULL)
  {
    drawing_draw();
  }
    
  return FALSE;
}

static gboolean on_mouse_pressed(GtkWidget* widget, GdkEventButton *event) 
{
  log_to_console("drawing.h - mouse pressed: button %d at %f/%f\n", event->button, event->x_root, event->y_root);
  if (drawing_mouse_pressed != NULL)
  {
    drawing_mouse_pressed(event->button, (int)event->x_root, (int)event->y_root);
  }
  return TRUE;
}

static gboolean on_mouse_released(GtkWidget* widget, GdkEventButton *event) 
{
  log_to_console("drawing.h - mouse released: button %d at %f/%f\n", event->button, event->x_root, event->y_root);
  if (drawing_mouse_released != NULL)
  {
    drawing_mouse_released(event->button, (int)event->x_root, (int)event->y_root);
  }
  return TRUE;
}

static gboolean on_mouse_moved(GtkWidget* widget, GdkEvent *event) 
{
  if (event->type==GDK_MOTION_NOTIFY)
  {
    GdkEventMotion* e=(GdkEventMotion*)event;
    guint x = (guint)e->x;
    guint y = (guint)e->y;
    log_to_console("drawing.h - mouse moved to %u/%u\n", x, y);    
    if (drawing_mouse_moved != NULL)
    {
      drawing_mouse_moved((int)x, (int)y);
    }
  }    
  return TRUE;
}

static gboolean on_key_pressed(GtkWidget* widget, GdkEventKey *event) 
{
  log_to_console("drawing.h - key pressed: %s (keycode %d)\n", event->string, event->keyval);
  if (drawing_key_pressed)
  {
    drawing_key_pressed(event->string, event->keyval);
  }
  return TRUE;
}

static gboolean on_key_released(GtkWidget* widget, GdkEventKey *event) 
{
  log_to_console("drawing.h - key released: %s (keycode %d)\n", event->string, event->keyval);
  if (drawing_key_released)
  {
    drawing_key_released(event->string, event->keyval);
  }  
  return TRUE;
}

void drawing_static_init(int width, int height)
{
  drawing_cairo_surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, width, height);
  drawing_cairo = cairo_create (drawing_cairo_surface);

  cairo_select_font_face(drawing_cairo, "serif", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
}

void drawing_static_write_png(char* filename)
{
  cairo_surface_write_to_png(drawing_cairo_surface, filename);
}

void drawing_dynamic_init()
{
  int argc = 0;
  gtk_init(&argc, NULL);

  drawing_gtk_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_events(drawing_gtk_window, GDK_POINTER_MOTION_MASK);

  drawing_gtk_area = gtk_drawing_area_new();
  gtk_container_add(GTK_CONTAINER(drawing_gtk_window), drawing_gtk_area);  

  g_signal_connect(G_OBJECT(drawing_gtk_area), "draw", G_CALLBACK(on_draw_event), NULL);  
  g_signal_connect(G_OBJECT(drawing_gtk_window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
  g_signal_connect(G_OBJECT(drawing_gtk_window), "button-press-event", G_CALLBACK(on_mouse_pressed), NULL);
  g_signal_connect(G_OBJECT(drawing_gtk_window), "button-release-event", G_CALLBACK(on_mouse_released), NULL);
  g_signal_connect(G_OBJECT(drawing_gtk_window), "motion-notify-event", G_CALLBACK(on_mouse_moved), NULL);
  g_signal_connect(G_OBJECT(drawing_gtk_window), "key-press-event", G_CALLBACK(on_key_pressed), NULL);
  g_signal_connect(G_OBJECT(drawing_gtk_window), "key-release-event", G_CALLBACK(on_key_released), NULL);

  //gtk_window_set_default_size(GTK_WINDOW(drawing_gtk_window), 270, 260); 
  gtk_window_fullscreen(GTK_WINDOW(drawing_gtk_window));
  gtk_window_set_title(GTK_WINDOW(drawing_gtk_window), "Drawing");

  gtk_widget_show_all(drawing_gtk_window);

  gtk_main();
}

void drawing_clear(double red, double green, double blue)
{
  cairo_set_source_rgb(drawing_cairo, red, green, blue);
  cairo_paint(drawing_cairo);
}

void drawing_dynamic_register_draw(void (*handler)())
{
  drawing_draw = handler;
}

void drawing_dynamic_register_key_pressed(void (*handler)(char*, int))
{
  drawing_key_pressed = handler;
}

void drawing_dynamic_register_key_released(void (*handler)(char*, int))
{
  drawing_key_released = handler;
}

void drawing_dynamic_register_mouse_pressed(void (*handler)(int, int, int))
{
  drawing_mouse_pressed = handler;
}

void drawing_dynamic_register_mouse_released(void (*handler)(int, int, int))
{
  drawing_mouse_released = handler;
}

void drawing_dynamic_register_mouse_moved(void (*handler)(int, int))
{
  drawing_mouse_moved = handler;
}
