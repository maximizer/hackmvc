<?hh
/**
 * Router 
 */
class Router
{
    private Map<string, Route> $routeMap;
    
    private function getServerMap() : Map<string, mixed> {
        return Map::fromArray($_SERVER);
    } 
    
    private function getControllerAction() : Map<string, string> {
        
        $pathInfo = $this->getServerMap()->get("PATH_INFO");
        $pathParts = explode("/", $pathInfo);
        $pathParts = array_filter($pathParts);
        
        $finalParts = new Vector<string>();
        
        foreach($pathParts as $part) {
            $finalParts[] = $part;
        }
        
        $controllerAction = new Map<string, string>();
        
        $controllerAction['controller'] = isset($finalParts[0]) ? ucfirst($finalParts[0]) : 'index';
        $controllerAction['action'] = isset($finalParts[1]) ? $finalParts[1] : 'index';
        
        return $controllerAction;
    }
    
    public function registerRoute(string $pattern, Route $route) : void {
        $this->routeMap[$pattern] = $route;
    }
    
    public function dispatch() : void {
        
        require __DIR__ . '/../controllers/' . $this->getControllerAction()->get('controller') . ".hh"; 
        $controllerName = $this->getControllerAction()->get('controller');
        $controller = new $controllerName();
        $actionName = $this->getControllerAction()->get('action');
        $controller->$actionName();
    }
    
}