<?hh
require __DIR__.'/src/Controller.hh';
require __DIR__.'/src/Route.hh';
require __DIR__.'/src/Router.hh';


$router = new Router();
$router->registerRoute("/foo", new Route("Foo.php", "index"));

$router->dispatch();