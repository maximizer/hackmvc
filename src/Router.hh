<?hh
/**
 * Hack MVC
 *
 * Router 
 *
 * @author Patrick Mizer
 */

class Router
{
    private Map<string, Route> $routeMap;
    
    private function getServerMap() : Map<string, mixed> {
        return Map::fromArray($_SERVER);
    } 
    
    private function getDefaultRoute() : Route {
        
        $pathInfo = $this->getServerMap()->get("PATH_INFO");
        $pathParts = explode("/", $pathInfo);
        $pathParts = array_filter($pathParts);
        
        $finalParts = new Vector<string>();
        
        foreach($pathParts as $part) {
            $finalParts[] = $part;
        }
        
        $controller = isset($finalParts[0]) ? ucfirst($finalParts[0]) : 'Index';
        $action = isset($finalParts[1]) ? $finalParts[1] : 'index';

        return new Route($controller, $action);
    }
    
    public function registerRoute(string $pattern, Route $route) : void {
        $this->routeMap[$pattern] = $route;
    }
    
    public function dispatch() : void {

        /* First check to see if we have a custom route */
        if(isset($this->routeMap[$this->getServerMap()->get("PATH_INFO")])) {
            $route = $this->routeMap[$this->getServerMap()->get("PATH_INFO")];
        } else {
            $route = $this->getDefaultRoute();
        }

        $controllerName = $route->getController();
        if(!@include __DIR__ . '/../controllers/' . $controllerName . ".hh" ) {
            die("No such controller: $controllerName" );
        }

        $controller = new $controllerName();

        $actionName = $route->getAction() . "Action";
        if(!method_exists($controller, $actionName)) {
            die("No such action: $controllerName::$actionName");
        }
        $controller->$actionName();
    }
}