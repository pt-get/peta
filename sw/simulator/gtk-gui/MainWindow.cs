
// This file has been generated by the GUI designer. Do not modify.

public partial class MainWindow
{
	private global::Gtk.Table _table;
	
	private global::Gtk.ScrolledWindow GtkScrolledWindow;
	
	private global::Gtk.TextView _log;

	protected virtual void Build ()
	{
		global::Stetic.Gui.Initialize (this);
		// Widget MainWindow
		this.Name = "MainWindow";
		this.Title = global::Mono.Unix.Catalog.GetString ("MainWindow");
		this.WindowPosition = ((global::Gtk.WindowPosition)(4));
		// Container child MainWindow.Gtk.Container+ContainerChild
		this._table = new global::Gtk.Table (((uint)(3)), ((uint)(3)), false);
		this._table.Name = "_table";
		this._table.RowSpacing = ((uint)(6));
		this._table.ColumnSpacing = ((uint)(6));
		// Container child _table.Gtk.Table+TableChild
		this.GtkScrolledWindow = new global::Gtk.ScrolledWindow ();
		this.GtkScrolledWindow.Name = "GtkScrolledWindow";
		this.GtkScrolledWindow.ShadowType = ((global::Gtk.ShadowType)(1));
		// Container child GtkScrolledWindow.Gtk.Container+ContainerChild
		this._log = new global::Gtk.TextView ();
		this._log.CanFocus = true;
		this._log.Name = "_log";
		this._log.Editable = false;
		this._log.AcceptsTab = false;
		this.GtkScrolledWindow.Add (this._log);
		this._table.Add (this.GtkScrolledWindow);
		this.Add (this._table);
		if ((this.Child != null)) {
			this.Child.ShowAll ();
		}
		this.DefaultWidth = 400;
		this.DefaultHeight = 300;
		this.Show ();
		this.DeleteEvent += new global::Gtk.DeleteEventHandler (this.OnDeleteEvent);
	}
}
