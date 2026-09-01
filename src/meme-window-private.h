#pragma once
#include "meme-window.h"
#include <adwaita.h>
#include "meme-core.h"
#include "meme-renderer.h"

typedef struct {
    GdkPixbuf *pixbuf;
    guint      delay_ms;
} GifFrame;

struct _MemeWindow {
    AdwApplicationWindow parent_instance;
    AdwPreferencesGroup *layer_group;
    AdwActionRow *open_template_row;
    AdwPreferencesGroup *transform_group;
    AdwPreferencesGroup *draw_group;
    AdwOverlaySplitView *split_view;
    AdwToastOverlay *copy_clip_feedback;
    GtkStack *content_stack;
    GtkPicture *meme_preview;
    GtkDrawingArea *crop_overlay_area;
    GtkImage *add_text_button;
    AdwActionRow *font_choose_row;
    GtkFontDialogButton *font_choose_btn;
    GtkFrame        *layer_text_container;
    GtkTextView     *layer_text_view;
    AdwActionRow *layer_font_size_row;
    GtkSpinButton *layer_font_size;
    GtkMenuButton *main_menu_button;    
    GtkButton *export_button, *copy_clipboard_button, *zoom_in, *zoom_out;
    GtkButton *load_image_button, *pill_btn_open_image, *clear_button, *add_image_button;
    GtkButton *import_template_button, *delete_template_button;
    GtkButton *select_all_button;
    GtkButton *select_mode_button;
    GtkButton *restore_templates_button;
    gboolean template_select_mode;
    GtkToggleButton *deep_fry_button, *cinematic_button, *crop_mode_button, *bw_button, *draw_mode_button;
    GtkFlowBox *template_gallery;
    GtkStack *template_content_stack;
    AdwDialog *template_window;
    GSettings *template_settings;
    GtkMenuButton *global_filters_button;
    GtkScale *layer_opacity_scale, *layer_rotation_scale;
    AdwComboRow *blend_mode_row;
    GtkButton *delete_layer_button;
    GtkButton *rotate_left_button, *rotate_right_button, *flip_h_button, *flip_v_button;
    GtkButton *crop_square_button, *crop_43_button, *crop_169_button;
    GtkButton *save_project_button, *load_project_button;   
    GdkPixbuf *template_image, *final_meme;
    GList *layers, *undo_stack, *redo_stack;
    ImageLayer *selected_layer; 
    DragType drag_type;
    GtkWidget *text_color_btn;
    GtkWidget *stroke_color_btn;
    GtkWidget *draw_color_btn;
    GtkSpinButton *draw_width_scale;
    
    GtkGestureDrag *drag_gesture;
    ResizeHandle active_crop_handle;    
    double drag_start_x, drag_start_y;
    double drag_obj_start_x, drag_obj_start_y, drag_obj_start_scale, drag_obj_start_h;
    double zoom_level;
    double crop_x, crop_y, crop_w, crop_h;
    GdkPixbuf *crop_session_template_snapshot;

    GArray *draw_points;
    GdkRGBA draw_color;
    double draw_line_width;

    gboolean  template_is_gif;
    gchar    *template_gif_path;
    GArray   *gif_frames;
    guint     gif_frame_index;
    guint     gif_timeout_id;
    GtkBox *export_loading_screen;
    GtkPopover *file_popover;

    GtkButton *footer_add_image_button, *footer_add_text_button;
    GtkButton *footer_copy_clipboard_button, *footer_delete_layer_button;
    GtkButton *footer_zoom_in, *footer_zoom_out, *footer_clear_button;
    GtkToggleButton *footer_crop_mode_button, *footer_cinematic_button, *footer_deep_fry_button, *footer_bw_button, *footer_draw_mode_button;
    GtkMenuButton *footer_global_filters_button;
    GtkButton *footer_rotate_left_button;
    GtkButton *footer_rotate_right_button;
    GtkButton *footer_flip_h_button;
    GtkButton *footer_flip_v_button;
    GtkButton *footer_crop_square_button;
    GtkButton *footer_crop_43_button;
    GtkButton *footer_crop_169_button;

    GtkBox *footer_tools_page;
    GtkBox *footer_transform_page;
    GtkBox *footer_draw_page;
    GtkWidget *footer_draw_color_btn;
    GtkSpinButton *footer_draw_width_scale;
    GtkButton *footer_exit_draw_button;
    GtkBox *footer_text_page;
    GtkFontDialogButton *footer_font_choose_btn;
    GtkWidget *footer_text_color_btn;
    GtkWidget *footer_stroke_color_btn;
    GtkFrame *footer_layer_text_container;
    GtkTextView *footer_layer_text_view;
    GtkSpinButton *footer_layer_font_size;
    GtkButton *footer_text_delete_button;
    GtkButton *footer_exit_text_button;
};

void sync_ui_with_layer(MemeWindow *self);
void render_meme(MemeWindow *self);
void on_clear_clicked(MemeWindow *self);
void apply_zoom(MemeWindow *self);
void update_template_image(MemeWindow *self, GdkPixbuf *new_pixbuf);

GArray  *meme_gif_decode_frames (const char *path);
void     meme_gif_frames_free (GArray *frames);
void     meme_window_start_gif_animation (MemeWindow *self);
void     meme_window_stop_gif_animation (MemeWindow *self);
void     meme_window_pause_gif_animation (MemeWindow *self);
void     meme_window_resume_gif_animation (MemeWindow *self);
void     meme_window_transform_gif_frames_rotate (MemeWindow *self, gboolean clockwise);
void     meme_window_transform_gif_frames_flip (MemeWindow *self, gboolean horizontal);
void     meme_window_transform_gif_frames_crop (MemeWindow *self, int x, int y, int w, int h);
