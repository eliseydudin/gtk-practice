#include <adwaita.h>
#include <stdio.h>

void activate_app(GtkApplication *app) {
  GtkWidget *window = adw_application_window_new(app);
  GtkWidget *toolbar_view = adw_toolbar_view_new();
  GtkWidget *header_bar = adw_header_bar_new();
  GtkWidget *label = gtk_label_new("hallooooooo");

  adw_toolbar_view_add_top_bar(ADW_TOOLBAR_VIEW(toolbar_view), header_bar);
  adw_toolbar_view_set_content(ADW_TOOLBAR_VIEW(toolbar_view), label);

  gtk_window_set_title(GTK_WINDOW(window), "hai :3");
  adw_application_window_set_content(ADW_APPLICATION_WINDOW(window),
                                     toolbar_view);
  gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, const char *argv[]) {
  puts("Hello, World!");

  g_autoptr(AdwApplication) app = adw_application_new("org.example.Hello", 0);
  g_signal_connect(app, "activate", G_CALLBACK(activate_app), NULL);

  return g_application_run(G_APPLICATION(app), argc, (char **)argv);
}
