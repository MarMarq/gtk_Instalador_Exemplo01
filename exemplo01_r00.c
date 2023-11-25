#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

void on_button_salvar_clicked(GtkButton *button, gpointer user_data) {
    //GtkWidget *user_data;

    GtkWidget *dialog;
    GtkFileChooser *chooser;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_SAVE;

    // Cria o diálogo de escolha de arquivo
    dialog = gtk_file_chooser_dialog_new("Salvar Arquivo",
                                         GTK_WINDOW(user_data),
                                         action,
                                         "_Cancelar",
                                         GTK_RESPONSE_CANCEL,
                                         "_Salvar",
                                         GTK_RESPONSE_ACCEPT,
                                         NULL);

    chooser = GTK_FILE_CHOOSER(dialog);

    // Configura o diálogo para permitir a criação de novos arquivos
    gtk_file_chooser_set_do_overwrite_confirmation(chooser, TRUE);

    // Adiciona um filtro para permitir apenas a seleção de arquivos .txt
    GtkFileFilter *filter = gtk_file_filter_new();
    gtk_file_filter_set_name(filter, "Arquivos de Texto");
    gtk_file_filter_add_pattern(filter, "*.txt");
    gtk_file_chooser_add_filter(chooser, filter);

    // Define um nome padrão com a extensão .txt
    gtk_file_chooser_set_current_name(chooser, "config.txt");

    // Exibe o diálogo e obtém a resposta do usuário
    gint result = gtk_dialog_run(GTK_DIALOG(dialog));

    if (result == GTK_RESPONSE_ACCEPT) {
        // Se o usuário clicou em "Salvar", obtém o caminho do arquivo escolhido
        char *filename = gtk_file_chooser_get_filename(chooser);
        g_print("Arquivo selecionado: %s\n", filename);

                // Abre o arquivo para escrita
        FILE *file = fopen(filename, "w");
        if (file != NULL) {
            // Escreve um conteúdo de exemplo no arquivo
//            fprintf(file, "Conteúdo de exemplo\n");


            // Fecha o arquivo
            fclose(file);

            g_print("Arquivo salvo com sucesso.\n");
        } else {
            g_print("Erro ao abrir o arquivo para escrita.\n");
        }

        g_free(filename);
    }

    // Fecha o diálogo
    gtk_widget_destroy(dialog);
}


int main(int argc, char *argv[]) {
    GtkBuilder *builder;
    GtkWidget *window;

    GtkWidget *btn_salva;
    GtkWidget *btn_sair;
    GtkWidget *img_imagem01;


    //int i = 0;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "gtk_glade_exemplo01-r00.glade", NULL);

    //Retorna o objeto Window, para mostrá-lo mais tarde
	window = GTK_WIDGET(gtk_builder_get_object (builder, "window_exemplo01"));          

    btn_salva    = GTK_WIDGET(gtk_builder_get_object (builder,"gtk_button_salvar"));
    btn_sair   = GTK_WIDGET(gtk_builder_get_object (builder,"gtk_button_sair"));
    img_imagem01 = GTK_WIDGET(gtk_builder_get_object (builder,"gtk_my_image01"));

    gtk_builder_connect_signals(builder, NULL);
    g_object_unref (G_OBJECT (builder));

    g_signal_connect(btn_salva, "clicked", G_CALLBACK(on_button_salvar_clicked), NULL);
    g_signal_connect(btn_sair, "clicked", G_CALLBACK(gtk_main_quit), window);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
