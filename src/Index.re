type root;
[@bs.module "react-dom/client"]
external createRoot: Dom.element => root = "createRoot";

[@bs.send] external render: (root, React.element) => unit = "render";

ReactDOM.querySelector("#root")
->(
    fun
    | Some(root) => {
        let app = createRoot(root);
        render(app, <App />);
      }
    | None =>
      Js.Console.error(
        "Failed to start React: couldn't find the #root element",
      )
  );
